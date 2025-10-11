"""
A* Pathfinding Algorithm (Python Implementation)

This algorithm finds the shortest path between two points on a grid
using a heuristic (Manhattan distance). It combines Dijkstra’s optimal
pathfinding with heuristic-based search for efficiency.

Time Complexity: O(E log V)
Space Complexity: O(V)
"""

from heapq import heappush, heappop

def heuristic(a, b):
    """Heuristic function: Manhattan distance."""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star_search(grid, start, goal):
    """
    Performs A* search on a 2D grid.
    
    Args:
        grid (list[list[int]]): 0 = free cell, 1 = obstacle
        start (tuple): (row, col) start position
        goal (tuple): (row, col) goal position
    
    Returns:
        path (list[tuple]): Shortest path as list of coordinates.
    """
    rows, cols = len(grid), len(grid[0])
    open_set = []
    heappush(open_set, (0, start))
    
    came_from = {}
    g_score = {start: 0}
    
    while open_set:
        _, current = heappop(open_set)
        
        if current == goal:
            # Reconstruct path
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]
        
        neighbors = [
            (current[0] + dx, current[1] + dy)
            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]
        ]
        
        for n in neighbors:
            if 0 <= n[0] < rows and 0 <= n[1] < cols and grid[n[0]][n[1]] == 0:
                tentative_g = g_score[current] + 1
                if tentative_g < g_score.get(n, float('inf')):
                    came_from[n] = current
                    g_score[n] = tentative_g
                    f_score = tentative_g + heuristic(n, goal)
                    heappush(open_set, (f_score, n))
    
    return None  # No path found

# Example usage:
if __name__ == "__main__":
    grid = [
        [0, 1, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    start = (0, 0)
    goal = (4, 4)
    path = a_star_search(grid, start, goal)
    print("Shortest Path:", path)
