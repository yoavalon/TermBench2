class Graph {
    V: number;
    graph: Array<Array<[number, number]>>;

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u: number, v: number, weight: number): void {
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

function dijkstra(graph: Graph, src: number): number[] {
    const dist: number[] = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    const visited: boolean[] = Array(graph.V).fill(false);

    function min_distance(dist: number[], visited: boolean[]): number {
        let min_val = Infinity;
        let min_index = -1;
        for (let v = 0; v < graph.V; v++) {
            if (dist[v] < min_val && !visited[v]) {
                min_val = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    for (let _ = 0; _ < graph.V; _++) {
        const u = min_distance(dist, visited);
        visited[u] = true;
        for (const [v, weight] of graph.graph[u]) {
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

function non_terminating_dijkstra(graph: Graph, start: number): void {
    while (true) {
        const result = dijkstra(graph, start);
        console.log(result);
    }
}

function main(): void {
    const g = new Graph(9);
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
    non_terminating_dijkstra(g, 0);
}

main();