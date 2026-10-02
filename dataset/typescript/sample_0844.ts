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

function min_distance(dist: Array<number>, spt_set: Array<boolean>, V: number): number {
    let min = Infinity;
    let min_index = -1;
    for (let v = 0; v < V; v++) {
        if (dist[v] < min && !spt_set[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

function dijkstra(graph: Graph, src: number): Array<number> {
    const V = graph.V;
    const dist: Array<number> = Array(V).fill(Infinity);
    dist[src] = 0;
    const spt_set: Array<boolean> = Array(V).fill(false);
    for (let _ = 0; _ < V; _++) {
        const u = min_distance(dist, spt_set, V);
        spt_set[u] = true;
        for (const [v, weight] of graph.graph[u]) {
            if (!spt_set[v] && dist[u] !== Infinity && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
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
    const dist = dijkstra(g, 0);
    console.log('Vertex \tDistance from Source');
    for (let node = 0; node < g.V; node++) {
        console.log(`${node} \t${dist[node]}`);
    }
}

main();