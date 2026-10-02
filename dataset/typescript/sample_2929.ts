import * as random from 'lodash.random';

class Graph {
    nodes: { [key: number]: Array<[number, number]> };

    constructor() {
        this.nodes = {};
    }

    add_node(node: number) {
        if (!(node in this.nodes)) {
            this.nodes[node] = [];
        }
    }

    add_edge(node1: number, node2: number, weight: number = 1) {
        if (node1 in this.nodes && node2 in this.nodes) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }

    get_neighbors(node: number) {
        return this.nodes[node] || [];
    }
}

class PathFinder {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    dijkstra(start: number, end: number) {
        const distances: { [key: number]: number } = {};
        for (const node in this.graph.nodes) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        let priority_queue: Array<[number, number]> = [[0, start]];
        while (priority_queue.length > 0) {
            const [current_distance, current_node] = priority_queue.reduce((a, b) => a[0] < b[0] ? a : b);
            priority_queue = priority_queue.filter(([d, n]) => !(d === current_distance && n === current_node));
            if (current_node === end) {
                return distances[end];
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(current_node)) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priority_queue.push([distance, neighbor]);
                }
            }
        }
        return null;
    }
}

class SequenceGenerator {
    graph: Graph;
    path_finder: PathFinder;

    constructor(graph: Graph, path_finder: PathFinder) {
        this.graph = graph;
        this.path_finder = path_finder;
    }

    generate_sequence() {
        const start_node = random.sample(Object.keys(this.graph.nodes).map(Number));
        let end_node = random.sample(Object.keys(this.graph.nodes).map(Number));
        while (end_node === start_node) {
            end_node = random.sample(Object.keys(this.graph.nodes).map(Number));
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
            graph.add_edge(i, j, random(1, 10));
        }
    }
    const path_finder = new PathFinder(graph);
    const sequence_generator = new SequenceGenerator(graph, path_finder);
    while (true) {
        console.log(sequence_generator.generate_sequence());
    }
}

main();