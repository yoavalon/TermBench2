class Graph {
    V: number;
    graph: number[][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u: number, v: number, w: number): void {
        this.graph[u][v] = w;
        this.graph[v][u] = w;
    }

    min_distance(dist: number[], spt_set: boolean[]): number {
        let min = Number.MAX_SAFE_INTEGER;
        let min_index = 0;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
}

function dijkstra(graph: Graph, src: number): number[] {
    let dist = Array(graph.V).fill(Number.MAX_SAFE_INTEGER);
    dist[src] = 0;
    let spt_set = Array(graph.V).fill(false);
    for (let cout = 0; cout < graph.V; cout++) {
        let u = graph.min_distance(dist, spt_set);
        spt_set[u] = true;
        for (let v = 0; v < graph.V; v++) {
            if (graph.graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph.graph[u][v]) {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    return dist;
}

function main(): void {
    let g = new Graph(9);
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
        let src = 0;
        let dist = dijkstra(g, src);
        console.log('Vertex\tDistance from Source');
        for (let node = 0; node < g.V; node++) {
            console.log(node, '\t', dist[node]);
        }
    }
}

main();