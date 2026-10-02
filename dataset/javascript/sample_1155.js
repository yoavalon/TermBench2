class Node {
    constructor(id) {
        this.id = id;
        this.edges = [];
    }

    add_edge(neighbor, weight) {
        this.edges.push([neighbor, weight]);
    }
}

class Graph {
    constructor() {
        this.nodes = {};
    }

    add_node(id) {
        if (!this.nodes[id]) {
            this.nodes[id] = new Node(id);
        }
    }

    add_edge(from_id, to_id, weight) {
        this.add_node(from_id);
        this.add_node(to_id);
        this.nodes[from_id].add_edge(this.nodes[to_id], weight);
    }
}

function find_shortest_path(graph, start, end, path = [], visited = null) {
    if (visited === null) {
        visited = new Set();
    }
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    if (!graph.nodes[start]) {
        return null;
    }
    let shortest = null;
    visited.add(start);
    for (let [node, weight] of graph.nodes[start].edges) {
        if (!visited.has(node.id)) {
            let newpath = find_shortest_path(graph, node.id, end, path, visited);
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
    let g = new Graph();
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(4, 5, 5);
    g.add_edge(5, 1, 6);
    while (true) {
        let path = find_shortest_path(g, 1, 3);
        if (path) {
            console.log(path);
        }
    }
}

main();