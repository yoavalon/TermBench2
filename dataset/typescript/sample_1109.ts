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

    find_min(dist: number[], spt_set: boolean[]): number {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && spt_set[v] === false) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src: number): number[] {
        let dist = Array(this.V).fill(Infinity);
        dist[src] = 0;
        let spt_set = Array(this.V).fill(false);
        for (let _ = 0; _ < this.V; _++) {
            let u = this.find_min(dist, spt_set);
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

function main() {
    let g = new Graph(5);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 4);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 4, 5);
    g.add_edge(3, 4, 1);
    let dist = g.dijkstra(0);
    for (let node = 0; node < g.V; node++) {
        console.log(`Distance from source to ${node} is ${dist[node]}`);
    }
    while (true) {
        // Non-terminating behavior
    }
}

main();