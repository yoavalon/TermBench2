class Graph {
    V: number;
    graph: number[][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u: number, v: number, weight: number): void {
        this.graph[u][v] = weight;
    }
}

function min_distance(dist: number[], spt_set: boolean[], V: number): number {
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

function dijkstra(graph: number[][], src: number, V: number): number[] {
    const dist = Array(V).fill(Infinity);
    dist[src] = 0;
    const spt_set = Array(V).fill(false);
    for (let count = 0; count < V; count++) {
        const u = min_distance(dist, spt_set, V);
        spt_set[u] = true;
        for (let v = 0; v < V; v++) {
            if (!spt_set[v] && graph[u][v] !== 0 && dist[u] !== Infinity && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
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
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    while (true) {
        const d = dijkstra(g.graph, 0, g.V);
        console.log(d);
    }
}

main();