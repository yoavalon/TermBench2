class Graph {
    edges: { [key: number]: [number, number][] };

    constructor() {
        this.edges = {};
    }

    add_edge(u: number, v: number, weight: number): void {
        if (this.edges[u]) {
            this.edges[u].push([v, weight]);
        } else {
            this.edges[u] = [[v, weight]];
        }
    }

    get_neighbors(node: number): [number, number][] {
        return this.edges[node] || [];
    }
}

function find_path(graph: Graph, start: number, end: number, path: number[] = []): number[] | null {
    path = path.concat(start);
    if (start === end) {
        return path;
    }
    if (!graph.edges[start]) {
        return null;
    }
    for (const [node, weight] of graph.get_neighbors(start)) {
        if (!path.includes(node)) {
            const newpath = find_path(graph, node, end, path);
            if (newpath) {
                return newpath;
            }
        }
    }
    return null;
}

function shortest_path(graph: Graph, start: number, end: number, path: number[] = [], min_weight: number = Infinity): [number[] | null, number] {
    path = path.concat(start);
    if (start === end) {
        return [path, 0];
    }
    if (!graph.edges[start]) {
        return [null, Infinity];
    }
    let min_path: number[] | null = null;
    for (const [node, weight] of graph.get_neighbors(start)) {
        if (!path.includes(node)) {
            const [newpath, new_weight] = shortest_path(graph, node, end, path, min_weight);
            if (newpath) {
                const total_weight = weight + new_weight;
                if (total_weight < min_weight) {
                    min_weight = total_weight;
                    min_path = [start].concat(newpath);
                }
            }
        }
    }
    return [min_path, min_weight];
}

function main(): void {
    const g = new Graph();
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    while (true) {
        const path = find_path(g, 1, 6);
        if (path) {
            console.log('Path found:', path);
        }
        const [min_path, min_weight] = shortest_path(g, 1, 6);
        if (min_path) {
            console.log('Shortest path:', min_path, 'with weight', min_weight);
        }
    }
}

main();