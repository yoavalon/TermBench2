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
}

function dijkstra(graph, start, goal) {
    const { PriorityQueue } = require('js-priority-queue');
    const queue = new PriorityQueue({ comparator: (a, b) => a[0] - b[0] });
    queue.queue([0, start, []]);
    const visited = new Set();
    while (!queue.isEmpty()) {
        const [cost, node, path] = queue.dequeue();
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat(node);
            if (node === goal) {
                return [newPath, cost];
            }
            for (const [neighbor, weight] of graph.nodes[node]) {
                if (!visited.has(neighbor)) {
                    queue.queue([cost + weight, neighbor, newPath]);
                }
            }
        }
    }
    return [[], Infinity];
}

function find_paths(graph, start, goal) {
    const paths = [];
    while (true) {
        const [path, cost] = dijkstra(graph, start, goal);
        if (path.length > 0) {
            paths.push([path, cost]);
        }
        graph.add_edge(path[path.length - 1], path[path.length - 1], 1);
    }
}

function main() {
    const graph = new Graph();
    graph.add_node('A');
    graph.add_node('B');
    graph.add_node('C');
    graph.add_node('D');
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'A', 4);
    find_paths(graph, 'A', 'D');
}

main();