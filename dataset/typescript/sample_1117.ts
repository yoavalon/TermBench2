class Graph {
    edges: { [key: number]: number[] };

    constructor() {
        this.edges = {};
    }

    add_edge(u: number, v: number) {
        if (!this.edges[u]) {
            this.edges[u] = [];
        }
        this.edges[u].push(v);
    }
}

function find_shortest_path(graph: Graph, start: number, end: number, path: number[] = []): number[] | null {
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    if (!graph.edges[start]) {
        return null;
    }
    let shortest: number[] | null = null;
    for (const node of graph.edges[start]) {
        if (!path.includes(node)) {
            const newpath = find_shortest_path(graph, node, end, path);
            if (newpath) {
                if (!shortest || newpath.length < shortest.length) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

function non_terminating_recursion(graph: Graph) {
    while (true) {
        find_shortest_path(graph, 1, 10);
    }
}

function main() {
    const graph = new Graph();
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 10);
    non_terminating_recursion(graph);
}

main();