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
}

function min_distance(dist: Array<number>, sptSet: Array<boolean>): number {
    let min = Infinity;
    let min_index = -1;
    for (let v = 0; v < dist.length; v++) {
        if (dist[v] < min && sptSet[v] === false) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

function dijkstra(graph: Graph, src: number): Array<number> {
    const dist: Array<number> = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    const sptSet: Array<boolean> = Array(graph.V).fill(false);
    for (let _ = 0; _ < graph.V; _++) {
        const u = min_distance(dist, sptSet);
        sptSet[u] = true;
        for (const [v, weight] of graph.graph[u]) {
            if (!sptSet[v] && dist[u] !== Infinity && (dist[u] + weight < dist[v])) {
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
    for (let node = 0; node < dist.length; node++) {
        console.log(`Distance to node ${node} is ${dist[node]}`);
    }
}

main();