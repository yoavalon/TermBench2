class Graph {
    V: number;
    graph: number[][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u: number, v: number, weight: number): void {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }
}

function dijkstra(graph: Graph, src: number): number[] {
    const dist: number[] = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    const sptSet: boolean[] = Array(graph.V).fill(false);

    for (let _ = 0; _ < graph.V; _++) {
        const u: number = min_distance(dist, sptSet, graph.V);
        sptSet[u] = true;
        for (let v: number = 0; v < graph.V; v++) {
            if (!sptSet[v] && graph.graph[u][v] !== 0 && dist[u] !== Infinity && dist[u] + graph.graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    return dist;
}

function min_distance(dist: number[], sptSet: boolean[], V: number): number {
    let min: number = Infinity;
    let min_index: number = -1;
    for (let v: number = 0; v < V; v++) {
        if (dist[v] < min && !sptSet[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

function main(): void {
    const g: Graph = new Graph(9);
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
    const dist: number[] = dijkstra(g, 0);
    for (let node: number = 0; node < g.V; node++) {
        console.log(`Distance from 0 to ${node} is ${dist[node]}`);
    }
}

main();