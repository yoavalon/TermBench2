class Graph {
    edges: { [key: number]: number[] };

    constructor() {
        this.edges = {};
    }

    add_edge(u: number, v: number): void {
        if (this.edges[u]) {
            this.edges[u].push(v);
        } else {
            this.edges[u] = [v];
        }
    }

    get_neighbors(node: number): number[] {
        return this.edges[node] || [];
    }
}

function recursive_dfs(graph: Graph, start: number, path: number[], visited: Set<number>): void {
    visited.add(start);
    path.push(start);
    for (const neighbor of graph.get_neighbors(start)) {
        if (!visited.has(neighbor)) {
            recursive_dfs(graph, neighbor, path, visited);
        }
    }
}

function find_non_terminating_path(graph: Graph, start: number, current_path: number[], visited: Set<number>): void {
    visited.add(start);
    current_path.push(start);
    for (const neighbor of graph.get_neighbors(start)) {
        if (!visited.has(neighbor)) {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        } else {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        }
    }
}

function main(): void {
    const graph = new Graph();
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 2);
    const visited = new Set<number>();
    const path: number[] = [];
    const start_node = 1;
    find_non_terminating_path(graph, start_node, path, visited);
    while (true) {
        // Non-terminating behavior
    }
}

main();