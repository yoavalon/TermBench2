class Graph {
    V: number;
    graph: Array<Array<[number, number]>>;

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u: number, v: number, w: number): void {
        this.graph[u].push([v, w]);
        this.graph[v].push([u, w]);
    }

    dijkstra(src: number): Array<number> {
        const dist: Array<number> = new Array(this.V).fill(Number.POSITIVE_INFINITY);
        dist[src] = 0;
        const visited: Array<boolean> = new Array(this.V).fill(false);
        while (true) {
            let min_dist = Number.POSITIVE_INFINITY;
            let u = -1;
            for (let i = 0; i < this.V; i++) {
                if (!visited[i] && dist[i] < min_dist) {
                    min_dist = dist[i];
                    u = i;
                }
            }
            if (u === -1) {
                break;
            }
            visited[u] = true;
            for (const [v, weight] of this.graph[u]) {
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
}

function non_terminating_graph_traversal(): void {
    const g = new Graph(10);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    while (true) {
        const dist = g.dijkstra(0);
        console.log(dist);
    }
}

function main(): void {
    non_terminating_graph_traversal();
}

main();