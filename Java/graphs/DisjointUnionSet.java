/**
 * Disjoint Set Union (Union-Find) data structure with path compression
 * and union by size optimizations.
 * 
 * Time Complexity: O(α(n)) amortized for both find and union operations,
 * where α(n) is the inverse Ackermann function (effectively constant).
 * Space Complexity: O(n) for parent and size arrays.
 */
class DSU {
    private int[] parent;
    private int[] size;
    
    /**
     * Initializes the DSU with n elements, each in its own set.
     * 
     * @param n the number of elements (0 to n-1)
     */
    public DSU(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    /**
     * Finds the representative (root) of the set containing x.
     * Implements path compression by making all nodes on the path
     * point directly to the root.
     * 
     * @param x the element whose set representative to find
     * @return the root of the set containing x
     */
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    /**
     * Unites the sets containing x and y.
     * Uses union by size: attaches smaller tree under root of larger tree.
     * 
     * @param x first element
     * @param y second element
     * @return true if sets were merged, false if already in same set
     */
    public boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        return true;
    }
    
    /**
     * Checks if two elements belong to the same set.
     * 
     * @param x first element
     * @param y second element
     * @return true if x and y are in the same set, false otherwise
     */
    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }
    
    /**
     * Returns the size of the set containing x.
     * 
     * @param x the element whose set size to retrieve
     * @return the number of elements in the set containing x
     */
    public int getSize(int x) {
        return size[find(x)];
    }
}
