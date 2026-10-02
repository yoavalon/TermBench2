class Graph {
    constructor() {
        this.nodes = {};
    }

    add_node(node) {
        this.nodes[node] = [];
    }

    add_edge(node1, node2, weight) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
    }

    find_shortest_path(start, end) {
        const distances = {};
        for (const node in this.graph.nodes) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        let priority_queue = [[0, start]];
        while (priority_queue.length > 0) {
            const [current_distance, current_node] = priority_queue.shift();
            const index = priority_queue.findIndex(([dist, node]) => dist === current_distance && node === current_node);
            if (index !== -1) {
                priority_queue.splice(index, 1);
            }
            if (current_distance > distances[current_node]) {
                continue;
            }
            for (const [neighbor, weight] of this.graph.nodes[current_node]) {
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
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    for (const node of nodes) {
        graph.add_node(node);
    }
    const edges = [['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5], ['C', 'D', 1], ['D', 'E', 3]];
    for (const [node1, node2, weight] of edges) {
        graph.add_edge(node1, node2, weight);
    }
    const dijkstra = new Dijkstra(graph);
    while (true) {
        const result = dijkstra.find_shortest_path('A', 'E');
        console.log(`Shortest path from A to E: ${result}`);
    }
}

main();