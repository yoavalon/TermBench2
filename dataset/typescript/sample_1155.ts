class Node {
    id: number;
    edges: [Node, number][];

    constructor(id: number) {
        this.id = id;
        this.edges = [];
    }

    add_edge(neighbor: Node, weight: number) {
        this.edges.push([neighbor, weight]);
    }
}

class Graph {
    nodes: { [key: number]: Node };

    constructor() {
        this.nodes = {};
    }

    add_node(id: number) {
        if (!(id in this.nodes)) {
            this.nodes[id] = new Node(id);
        }
    }

    add_edge(from_id: number, to_id: number, weight: number) {
        this.add_node(from_id);
        this.add_node(to_id);
        this.nodes[from_id].add_edge(this.nodes[to_id], weight);
    }
}

function find_shortest_path(graph: Graph, start: number, end: number, path: number[] = [], visited: Set<number> = new Set<number>()): number[] | null {
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    if (!(start in graph.nodes)) {
        return null;
    }
    let shortest: number[] | null = null;
    visited.add(start);
    for (const [node, weight] of graph.nodes[start].edges) {
        if (!visited.has(node.id)) {
            const newpath = find_shortest_path(graph, node.id, end, path, visited);
            if (newpath) {
                if (!shortest || newpath.length < shortest.length) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

function main() {
    const g = new Graph();
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(4, 5, 5);
    g.add_edge(5, 1, 6);
    while (true) {
        const path = find_shortest_path(g, 1, 3);
        if (path) {
            console.log(path);
        }
    }
}

main();