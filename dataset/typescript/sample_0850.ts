class Graph {
    graph: { [key: number]: Array<[number, number]> };

    constructor() {
        this.graph = {};
    }

    add_edge(u: number, v: number, weight: number): void {
        if (!this.graph[u]) this.graph[u] = [];
        if (!this.graph[v]) this.graph[v] = [];
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

function dijkstra(graph: Graph, start: number): { [key: number]: number } {
    const distances: { [key: number]: number } = {};
    for (const node in graph.graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const priority_queue: Array<[number, number]> = [[0, start]];
    while (priority_queue.length > 0) {
        const [current_distance, current_node] = priority_queue.shift()!;
        if (current_distance > distances[current_node]) {
            continue;
        }
        for (const [neighbor, weight] of graph.graph[current_node]) {
            const distance = current_distance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priority_queue.push([distance, neighbor]);
                priority_queue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return distances;
}

function find_shortest_path(graph: Graph, start: number, end: number): number {
    const distances = dijkstra(graph, start);
    return distances[end];
}

function main(): void {
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