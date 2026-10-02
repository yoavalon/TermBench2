class Graph {
    nodes: { [key: string]: string[] };

    constructor() {
        this.nodes = {};
    }

    add_node(node: string) {
        this.nodes[node] = [];
    }

    add_edge(node1: string, node2: string) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push(node2);
            this.nodes[node2].push(node1);
        }
    }
}

class PathFinder {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_path(start: string, end: string, path: string[] = []): string[] | null {
        path = path.concat([start]);
        if (start === end) {
            return path;
        }
        if (!this.graph.nodes[start]) {
            return null;
        }
        for (const node of this.graph.nodes[start]) {
            if (!path.includes(node)) {
                const newpath = this.find_path(node, end, path);
                if (newpath) {
                    return newpath;
                }
            }
        }
        return null;
    }
}

function main() {
    const g = new Graph();
    const nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'];
    for (const node of nodes) {
        g.add_node(node);
    }
    const edges = [
        ['A', 'B'], ['A', 'C'], ['B', 'D'], ['B', 'E'], ['C', 'F'], ['C', 'G'],
        ['D', 'H'], ['E', 'H'], ['F', 'H'], ['G', 'H']
    ];
    for (const edge of edges) {
        g.add_edge(...edge);
    }
    const pf = new PathFinder(g);
    while (true) {
        const path = pf.find_path('A', 'H');
        if (path) {
            console.log(path);
        } else {
            console.log('No path found');
        }
    }
}

main();