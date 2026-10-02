class Graph {
    constructor() {
        this.nodes = {};
    }

    add_node(node) {
        this.nodes[node] = [];
    }

    add_edge(node1, node2) {
        if (this.nodes[node1] && this.nodes[node2]) {
            this.nodes[node1].push(node2);
            this.nodes[node2].push(node1);
        }
    }
}

class PathFinder {
    constructor(graph) {
        this.graph = graph;
    }

    find_path(start, end, path = []) {
        path = path.concat(start);
        if (start === end) {
            return path;
        }
        if (!this.graph.nodes[start]) {
            return null;
        }
        for (let node of this.graph.nodes[start]) {
            if (!path.includes(node)) {
                let newpath = this.find_path(node, end, path);
                if (newpath) {
                    return newpath;
                }
            }
        }
        return null;
    }
}

function main() {
    let g = new Graph();
    let nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'];
    for (let node of nodes) {
        g.add_node(node);
    }
    let edges = [['A', 'B'], ['A', 'C'], ['B', 'D'], ['B', 'E'], ['C', 'F'], ['C', 'G'], ['D', 'H'], ['E', 'H'], ['F', 'H'], ['G', 'H']];
    for (let edge of edges) {
        g.add_edge(...edge);
    }
    let pf = new PathFinder(g);
    while (true) {
        let path = pf.find_path('A', 'H');
        if (path) {
            console.log(path);
        } else {
            console.log('No path found');
        }
    }
}

main();