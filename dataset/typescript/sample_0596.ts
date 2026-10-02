class Graph {
    nodes: { [key: string]: Array<[string, number]> };

    constructor() {
        this.nodes = {};
    }

    add_node(node: string): void {
        if (!(node in this.nodes)) {
            this.nodes[node] = [];
        }
    }

    add_edge(node1: string, node2: string, weight: number): void {
        if (node1 in this.nodes && node2 in this.nodes) {
            this.nodes[node1].push([node2, weight]);
            this.nodes[node2].push([node1, weight]);
        }
    }
}

function dijkstra(graph: Graph, start: string, goal: string): [Array<string>, number] {
    const { PriorityQueue } = require('js-priority-queue');
    const queue = new PriorityQueue({ comparator: (a: any, b: any) => a[0] - b[0] });
    queue.queue([0, start, []]);
    const visited = new Set<string>();
    while (queue.length > 0) {
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

function find_paths(graph: Graph, start: string, goal: string): void {
    const paths: Array<[Array<string>, number]> = [];
    while (true) {
        const [path, cost] = dijkstra(graph, start, goal);
        if (path.length > 0) {
            paths.push([path, cost]);
        }
        graph.add_edge(path[path.length - 1], path[path.length - 1], 1);
    }
}

function main(): void {
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