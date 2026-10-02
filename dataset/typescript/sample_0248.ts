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

class Dijkstra {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    min_distance(dist: Array<number>, spt_set: Array<boolean>): number {
        let min_val = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.graph.V; v++) {
            if (dist[v] < min_val && !spt_set[v]) {
                min_val = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src: number): Array<number> {
        let dist: Array<number> = Array(this.graph.V).fill(Infinity);
        dist[src] = 0;
        let spt_set: Array<boolean> = Array(this.graph.V).fill(false);
        for (let _ = 0; _ < this.graph.V; _++) {
            let u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let [v, weight] of this.graph.graph[u]) {
                if (!spt_set[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
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
    let dijkstra = new Dijkstra(g);
    let result = dijkstra.dijkstra(0);
    console.log(result);
}

main();