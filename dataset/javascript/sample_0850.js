class Graph {
    constructor() {
        this.graph = {};
    }

    add_edge(u, v, weight) {
        if (!this.graph[u]) this.graph[u] = [];
        if (!this.graph[v]) this.graph[v] = [];
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

function dijkstra(graph, start) {
    const distances = {};
    for (const node in graph.graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const priorityQueue = [[0, start]];

    while (priorityQueue.length > 0) {
        const [current_distance, current_node] = priorityQueue.shift();
        if (current_distance > distances[current_node]) continue;
        for (const [neighbor, weight] of graph.graph[current_node]) {
            const distance = current_distance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priorityQueue.push([distance, neighbor]);
                priorityQueue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return distances;
}

function find_shortest_path(graph, start, end) {
    const distances = dijkstra(graph, start);
    return distances[end];
}

function main() {
    const g = new Graph();
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    const shortest_path = find_shortest_path(g, 0, 4);
    console.log(shortest_path);
}

main();