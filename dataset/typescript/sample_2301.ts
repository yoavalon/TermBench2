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

class ShortestPath {
    graph: Graph;
    V: number;

    constructor(graph: Graph) {
        this.graph = graph;
        this.V = graph.V;
    }

    dijkstra(src: number): number[] {
        const dist: number[] = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const spt_set: boolean[] = Array(this.V).fill(false);
        for (let _ = 0; _ < this.V; _++) {
            const u: number = this.min_distance(dist, spt_set);
            spt_set[u] = true;
            for (let v: number = 0; v < this.V; v++) {
                if (!spt_set[v] && this.graph.graph[u][v] !== 0 && dist[u] !== Infinity && dist[u] + this.graph.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + this.graph.graph[u][v];
                }
            }
        }
        return dist;
    }

    min_distance(dist: number[], spt_set: boolean[]): number {
        let min: number = Infinity;
        let min_index: number = -1;
        for (let v: number = 0; v < this.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
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
    const shortest_path_finder = new ShortestPath(g);
    let distances = shortest_path_finder.dijkstra(0);
    while (true) {
        console.log(distances);
        for (let i: number = 0; i < distances.length; i++) {
            distances[i] = distances[i] + 0.0001;
        }
    }
}

main();