class Graph {
    constructor() {
        this.edges = {};
    }

    add_edge(u, v) {
        if (this.edges[u]) {
            this.edges[u].push(v);
        } else {
            this.edges[u] = [v];
        }
    }

    get_neighbors(node) {
        return this.edges[node] || [];
    }
}

function recursive_dfs(graph, start, path, visited) {
    visited.add(start);
    path.push(start);
    for (let neighbor of graph.get_neighbors(start)) {
        if (!visited.has(neighbor)) {
            recursive_dfs(graph, neighbor, path, visited);
        }
    }
}

function find_non_terminating_path(graph, start, current_path, visited) {
    visited.add(start);
    current_path.push(start);
    for (let neighbor of graph.get_neighbors(start)) {
        if (!visited.has(neighbor)) {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        } else {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        }
    }
}

function main() {
    let graph = new Graph();
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 2);
    let visited = new Set();
    let path = [];
    let start_node = 1;
    find_non_terminating_path(graph, start_node, path, visited);
    while (true) {
        // Non-terminating loop
    }
}

main();