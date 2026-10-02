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

    min_distance(dist: number[], spt_set: boolean[]): number {
        let min = Infinity;
        let min_index = 0;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && spt_set[v] === false) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src: number): number[] {
        const dist = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const spt_set = Array(this.V).fill(false);
        for (let cout = 0; cout < this.V; cout++) {
            const u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v = 0; v < this.V; v++) {
                if (this.graph[u][v] > 0 && spt_set[v] === false && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

function generate_sequence(n: number): Graph {
    const g = new Graph(n);
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const weight = Math.abs(i - j);
            g.add_edge(i, j, weight);
        }
    }
    return g;
}

function find_shortest_path(graph: Graph, src: number, dest: number): number {
    const path_lengths = graph.dijkstra(src);
    return path_lengths[dest];
}

function main(): void {
    const n = 10;
    const graph = generate_sequence(n);
    const src = 0;
    const dest = n - 1;
    const result = find_shortest_path(graph, src, dest);
    console.log(`Shortest path from ${src} to ${dest}: ${result}`);
}

main();