class Edge {
    constructor(source, destination, weight) {
        this.source = source;
        this.destination = destination;
        this.weight = weight;
    }
}

function findShortestPaths(edges, V, source) {
    const distances = new Array(V);
    for (let i = 0; i < V; i++) {
        distances[i] = Number.MAX_SAFE_INTEGER;
    }
    distances[source] = 0;

    // Relax all edges V-1 times
    for (let i = 1; i < V; i++) {
        for (const edge of edges) {
            const u = edge.source;
            const v = edge.destination;
            const weight = edge.weight;

            if (distances[u] !== Number.MAX_SAFE_INTEGER &&
                distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }

    // Check for negative weight cycle
    for (const edge of edges) {
        const u = edge.source;
        const v = edge.destination;
        const weight = edge.weight;

        if (distances[u] !== Number.MAX_SAFE_INTEGER &&
            distances[u] + weight < distances[v]) {
            // Negative weight cycle detected
            return null;
        }
    }

    return distances;
}

function printShortestPaths(distances) {
    if (distances === null) {
        console.log("Graph contains negative weight cycle!");
        return;
    }

    console.log("Vertex \t Distance from Source");
    for (let i = 0; i < distances.length; i++) {
        if (distances[i] === Number.MAX_SAFE_INTEGER) {
            console.log(i + "\t\t INFINITY");
        } else {
            console.log(i + "\t\t " + distances[i]);
        }
    }
}

// Test Case 1: Graph without negative cycle
console.log("Test Case 1: Graph without negative cycle");
const edges1 = [
    new Edge(0, 1, 4),
    new Edge(0, 2, 2),
    new Edge(1, 2, -1),
    new Edge(1, 3, 3),
    new Edge(2, 3, 1)
];
const V1 = 4;
const result1 = findShortestPaths(edges1, V1, 0);
printShortestPaths(result1);
console.log();

// Test Case 2: Graph with negative cycle
console.log("Test Case 2: Graph with negative cycle");
const edges2 = [
    new Edge(0, 1, 1),
    new Edge(1, 2, 2),
    new Edge(2, 3, 3),
    new Edge(3, 1, -7)
];
const V2 = 4;
const result2 = findShortestPaths(edges2, V2, 0);
printShortestPaths(result2);
console.log();

// Test Case 3: Graph with unreachable vertices
console.log("Test Case 3: Graph with unreachable vertices");
const edges3 = [
    new Edge(0, 1, 5),
    new Edge(1, 2, 2),
    new Edge(3, 4, 1)
];
const V3 = 5;
const result3 = findShortestPaths(edges3, V3, 0);
printShortestPaths(result3);

module.exports = { Edge, findShortestPaths, printShortestPaths };
