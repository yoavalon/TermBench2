const { PriorityQueue } = require('js-priority-queue');

class Graph {
    constructor() {
        this.nodes = {};
    }

    add_node(node) {
        if (!this.nodes[node]) {
            this.nodes[node] = [];
        }
    }

    add_edge(node1, node2, weight = 1) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }

    get_neighbors(node) {
        return this.nodes[node] || [];
    }
}

class PathFinder {
    constructor(graph) {
        this.graph = graph;
    }

    dijkstra(start, end) {
        const distances = {};
        for (const node in this.graph.nodes) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        const priorityQueue = new PriorityQueue({ comparator: (a, b) => a[0] - b[0] });
        priorityQueue.queue([0, start]);
        while (priorityQueue.length > 0) {
            const [current_distance, current_node] = priorityQueue.dequeue();
            if (current_node === end) {
                return distances[end];
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(current_node)) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priorityQueue.queue([distance, neighbor]);
                }
            }
        }
        return null;
    }
}

class SequenceGenerator {
    constructor(graph, path_finder) {
        this.graph = graph;
        this.path_finder = path_finder;
    }

    generate_sequence() {
        const start_node = Object.keys(this.graph.nodes)[Math.floor(Math.random() * Object.keys(this.graph.nodes).length)];
        let end_node = Object.keys(this.graph.nodes)[Math.floor(Math.random() * Object.keys(this.graph.nodes).length)];
        while (end_node === start_node) {
            end_node = Object.keys(this.graph.nodes)[Math.floor(Math.random() * Object.keys(this.graph.nodes).length)];
        }
        return this.path_finder.dijkstra(start_node, end_node);
    }
}

function main() {
    const graph = new Graph();
    const nodes = Array.from({ length: 10 }, (_, i) => i);
    for (const node of nodes) {
        graph.add_node(node);
    }
    for (let i = 0; i < 10; i++) {
        for (let j = i + 1; j < 10; j++) {
            graph.add_edge(i, j, Math.floor(Math.random() * 10) + 1);
        }
    }
    const path_finder = new PathFinder(graph);
    const sequence_generator = new SequenceGenerator(graph, path_finder);
    while (true) {
        console.log(sequence_generator.generate_sequence());
    }
}

main();