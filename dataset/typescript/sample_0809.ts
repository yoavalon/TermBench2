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

    min_distance(dist: number[], spt_set: boolean[]): number {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
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
        for (let count = 0; count < this.V; count++) {
            let u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v = 0; v < this.V; v++) {
                if (!spt_set[v] && this.graph[u][v] !== 0 && dist[u] !== Infinity && dist[u] + this.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

function process_graph(): Graph {
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
    return g;
}

function main(): void {
    let g = process_graph();
    let result = g.dijkstra(0);
    console.log(result);
}

main();