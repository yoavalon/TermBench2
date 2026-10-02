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

    dijkstra(start: number): number[] {
        const distance: number[] = Array(this.V).fill(Infinity);
        distance[start] = 0;
        const visited: boolean[] = Array(this.V).fill(false);

        const min_distance = (dist: number[], visited: boolean[]): number => {
            let min_dist = Infinity;
            let min_index = -1;
            for (let v = 0; v < this.V; v++) {
                if (!visited[v] && dist[v] < min_dist) {
                    min_dist = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        };

        for (let _ = 0; _ < this.V; _++) {
            const u = min_distance(distance, visited);
            visited[u] = true;
            for (const [v, weight] of this.graph[u]) {
                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        return distance;
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
    const start_vertex = 0;
    const distances = g.dijkstra(start_vertex);
    for (let i = 0; i < g.V; i++) {
        console.log(`Distance from ${start_vertex} to ${i} is ${distances[i]}`);
    }
}

main();