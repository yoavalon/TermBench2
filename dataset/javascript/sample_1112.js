class Graph {
    constructor() {
        this.nodes = {};
    }

    add_node(node) {
        if (!this.nodes[node]) {
            this.nodes[node] = [];
        }
    }

    add_edge(node1, node2, weight) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }

    get_neighbors(node) {
        return this.nodes[node] || [];
    }
}

class ShortestPath {
    constructor(graph) {
        this.graph = graph;
    }

    dijkstra(start, end) {
        const distances = {};
        for (const node in this.graph.nodes) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        let priority_queue = [[0, start]];
        while (priority_queue.length > 0) {
            const [current_distance, current_node] = priority_queue.shift();
            if (current_distance > distances[current_node]) {
                continue;
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(current_node)) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priority_queue.push([distance, neighbor]);
                }
            }
        }
        return distances[end];
    }
}

function main() {
    const graph = new Graph();
    for (let i = 0; i < 10; i++) {
        graph.add_node(i);
    }
    for (let i = 0; i < 10; i++) {
        graph.add_edge(i, (i + 1) % 10, 1);
    }
    const path_finder = new ShortestPath(graph);
    while (true) {
        const result = path_finder.dijkstra(0, 9);
        console.log(result);
    }
}

main();