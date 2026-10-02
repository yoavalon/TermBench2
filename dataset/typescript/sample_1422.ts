class Graph {
    V: number;
    graph: [number, number][][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u: number, v: number, w: number): void {
        this.graph[u].push([v, w]);
        this.graph[v].push([u, w]);
    }
}

class ShortestPath {
    graph: Graph;
    dist: number[];
    parent: number[];

    constructor(graph: Graph) {
        this.graph = graph;
        this.dist = Array(graph.V).fill(Infinity);
        this.parent = Array(graph.V).fill(-1);
    }

    bellman_ford(src: number): void {
        this.dist[src] = 0;
        for (let _ = 0; _ < this.graph.V - 1; _++) {
            for (let u = 0; u < this.graph.V; u++) {
                for (const [v, weight] of this.graph.graph[u]) {
                    if (this.dist[u] !== Infinity && this.dist[u] + weight < this.dist[v]) {
                        this.dist[v] = this.dist[u] + weight;
                        this.parent[v] = u;
                    }
                }
            }
        }
    }

    get_shortest_path(dst: number): number[] {
        const path: number[] = [];
        if (this.dist[dst] === Infinity) {
            return path;
        }
        while (dst !== -1) {
            path.push(dst);
            dst = this.parent[dst];
        }
        path.reverse();
        return path;
    }
}

function main(): void {
    const V = 5;
    const graph = new Graph(V);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 3, 7);
    graph.add_edge(1, 4, 9);
    graph.add_edge(2, 3, 4);
    graph.add_edge(2, 4, 2);
    graph.add_edge(3, 4, 11);
    graph.add_edge(3, 0, 2);
    graph.add_edge(4, 0, 7);
    const shortest_path_finder = new ShortestPath(graph);
    shortest_path_finder.bellman_ford(0);
    const path = shortest_path_finder.get_shortest_path(4);
    console.log(path);
}

main();