class Graph {
    nodes: { [key: number]: [number, number][] };

    constructor() {
        this.nodes = {};
    }

    add_node(node: number) {
        if (!this.nodes[node]) {
            this.nodes[node] = [];
        }
    }

    add_edge(from_node: number, to_node: number, weight: number) {
        if (this.nodes[from_node]) {
            this.nodes[from_node].push([to_node, weight]);
        }
    }
}

function dijkstra(graph: Graph, start: number, end: number): number {
    const distances: { [key: number]: number } = {};
    for (const node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const priority_queue: [number, number][] = [[0, start]];

    while (priority_queue.length > 0) {
        const [current_distance, current_node] = priority_queue.shift()!;
        if (current_distance > distances[current_node]) {
            continue;
        }
        for (const [neighbor, weight] of graph.nodes[current_node]) {
            const distance = current_distance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priority_queue.push([distance, neighbor]);
                priority_queue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return distances[end];
}

function main() {
    const graph = new Graph();
    graph.add_node(1);
    graph.add_node(2);
    graph.add_node(3);
    graph.add_node(4);
    graph.add_edge(1, 2, 10);
    graph.add_edge(1, 3, 15);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 4, 12);
    graph.add_edge(3, 4, 10);
    console.log(dijkstra(graph, 1, 4));
}

main();