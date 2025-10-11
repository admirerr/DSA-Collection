import heapq

def dijkstra(adj, V, source):
    """
    Dijkstra's Algorithm - Finds shortest path from source to all other vertices

    Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a source vertex
    to all other vertices in a weighted graph with non-negative edge weights.

    Args:
        adj: Adjacency list representation of the graph
        V: Number of vertices in the graph
        source: Starting vertex for shortest path calculation
    """

    # Initialize distance array with infinity for all vertices
    distance = [float('inf')] * V

    # Distance from source to itself is always 0
    distance[source] = 0

    # Priority queue (min-heap) to store (distance, vertex) pairs
    pq = [(0, source)]

    # Main algorithm loop - continues until all reachable vertices are processed
    while pq:
        # Extract vertex with minimum distance from priority queue
        d, u = heapq.heappop(pq)

        # Skip if already found a shorter path to this vertex
        if d > distance[u]:
            continue

        # Explore all neighbors of current vertex
        for neighbor, weight in adj[u]:
            # Relaxation step: Check if path through current vertex is shorter
            # than the previously known shortest path to the neighbor
            if distance[u] + weight < distance[neighbor]:
                # Update the shortest distance to the neighbor
                distance[neighbor] = distance[u] + weight

                # Add the neighbor to priority queue with updated distance
                heapq.heappush(pq, (distance[neighbor], neighbor))

    for i in range(V):
        print(f"Distance from source to {i} is {distance[i]}")

if __name__ == "__main__":

    # Number of vertices in the graph
    V = 5

    # Create adjacency list representation of the graph
    # adj[i] contains list of (neighbor, weight) tuples for vertex i
    adj = [[] for _ in range(V)]

    # Build the graph by adding edges
    # From vertex 0: edges to vertex 1 (weight 4) and vertex 2 (weight 1)
    adj[0].append((1, 4))
    adj[0].append((2, 1))

    # From vertex 1: edge to vertex 3 (weight 1)
    adj[1].append((3, 1))

    # From vertex 2: edges to vertex 1 (weight 2) and vertex 3 (weight 5)
    adj[2].append((1, 2))
    adj[2].append((3, 5))

    # From vertex 3: edge to vertex 4 (weight 3)
    adj[3].append((4, 3))

    dijkstra(adj, V, 0)
