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

function find_neighbors(graph, node) {
    if (graph.nodes[node]) {
        return graph.nodes[node];
    }
    return [];
}

function shortest_path(graph, start, end, path = []) {
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    let shortest = null;
    let neighbors = find_neighbors(graph, start);
    for (let [neighbor, weight] of neighbors) {
        if (!path.includes(neighbor)) {
            let new_path = shortest_path(graph, neighbor, end, path);
            if (new_path) {
                if (!shortest || new_path.length < shortest.length) {
                    shortest = new_path;
                }
            }
        }
    }
    return shortest;
}

function main() {
    let g = new Graph();
    let nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
    for (let node of nodes) {
        g.add_node(node);
    }
    let edges = [['A', 'B', 1], ['A', 'C', 4], ['B', 'C', 2], ['B', 'D', 5], ['C', 'D', 1], ['D', 'E', 3], ['E', 'F', 2]];
    for (let edge of edges) {
        g.add_edge(...edge);
    }
    console.log(shortest_path(g, 'A', 'F'));
}

main();