class Node {
    value: number;
    neighbors: Node[];

    constructor(value: number) {
        this.value = value;
        this.neighbors = [];
    }
}

class Graph {
    nodes: Node[];

    constructor() {
        this.nodes = [];
    }

    add_node(value: number): Node {
        const node = new Node(value);
        this.nodes.push(node);
        return node;
    }

    add_edge(node1: Node, node2: Node): void {
        node1.neighbors.push(node2);
        node2.neighbors.push(node1);
    }
}

function bfs_shortest_path(graph: Graph, start: Node, end: Node): number[] | null {
    const queue: [Node, number[]][] = [[start, [start.value]]];
    while (queue.length > 0) {
        const [vertex, path] = queue.shift()!;
        for (const next of vertex.neighbors.filter(n => !path.includes(n.value))) {
            if (next === end) {
                return path.concat(next.value);
            } else {
                queue.push([next, path.concat(next.value)]);
            }
        }
    }
    return null;
}

function main(): void {
    const graph = new Graph();
    const node1 = graph.add_node(1);
    const node2 = graph.add_node(2);
    const node3 = graph.add_node(3);
    const node4 = graph.add_node(4);
    const node5 = graph.add_node(5);
    graph.add_edge(node1, node2);
    graph.add_edge(node2, node3);
    graph.add_edge(node3, node4);
    graph.add_edge(node4, node5);
    graph.add_edge(node5, node1);
    while (true) {
        const path = bfs_shortest_path(graph, node1, node5);
        console.log(path);
    }
}

main();