public class BellmanFord {
    static class Edge {
        int source;
        int destination;
        int weight;

        Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }


    public static Integer[] findShortestPaths(Edge[] edges, int V, int source) {

        Integer[] distances = new Integer[V];
        for (int i = 0; i < V; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        distances[source] = 0;


        for (int i = 1; i < V; i++) {
            for (Edge edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;

                if (distances[u] != Integer.MAX_VALUE && 
                    distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }


        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != Integer.MAX_VALUE && 
                distances[u] + weight < distances[v]) {

                return null;
            }
        }

        return distances;
    }


    public static void printShortestPaths(Integer[] distances) {
        if (distances == null) {
            System.out.println("Graph contains negative weight cycle!");
            return;
        }

        System.out.println("Vertex \t Distance from Source");
        for (int i = 0; i < distances.length; i++) {
            if (distances[i] == Integer.MAX_VALUE) {
                System.out.println(i + "\t\t INFINITY");
            } else {
                System.out.println(i + "\t\t " + distances[i]);
            }
        }
    }

    public static void main(String[] args) {

        System.out.println("Test Case 1: Graph without negative cycle");
        Edge[] edges1 = new Edge[] {
            new Edge(0, 1, 4),
            new Edge(0, 2, 2),
            new Edge(1, 2, -1),
            new Edge(1, 3, 3),
            new Edge(2, 3, 1)
        };
        int V1 = 4;
        Integer[] result1 = findShortestPaths(edges1, V1, 0);
        printShortestPaths(result1);
        System.out.println();


        System.out.println("Test Case 2: Graph with negative cycle");
        Edge[] edges2 = new Edge[] {
            new Edge(0, 1, 1),
            new Edge(1, 2, 2),
            new Edge(2, 3, 3),
            new Edge(3, 1, -7)
        };
        int V2 = 4;
        Integer[] result2 = findShortestPaths(edges2, V2, 0);
        printShortestPaths(result2);
        System.out.println();


        System.out.println("Test Case 3: Graph with unreachable vertices");
        Edge[] edges3 = new Edge[] {
            new Edge(0, 1, 5),
            new Edge(1, 2, 2),
            new Edge(3, 4, 1)
        };
        int V3 = 5;
        Integer[] result3 = findShortestPaths(edges3, V3, 0);
        printShortestPaths(result3);
    }
}