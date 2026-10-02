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

    print_solution(dist: number[]): void {
        console.log('Vertex \t Distance from Source');
        for (let node = 0; node < this.V; node++) {
            console.log(node, '\t', dist[node]);
        }
    }

    min_distance(dist: number[], spt_set: boolean[]): number {
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

    dijkstra(src: number): void {
        const dist: number[] = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const spt_set: boolean[] = Array(this.V).fill(false);
        for (let cout = 0; cout < this.V; cout++) {
            const u = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v = 0; v < this.V; v++) {
                if (this.graph[u][v] > 0 && spt_set[v] === false && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        this.print_solution(dist);
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
    g.dijkstra(0);
}

main();