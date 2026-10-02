class Graph {
    V: number;
    graph: [number, number][][];

    constructor(vertices: number) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u: number, v: number, w: number): void {
        this.graph[u].push([v, w]);
    }

    bellman_ford(src: number): (number | boolean)[] {
        const dist: (number | boolean)[] = Array(this.V).fill(Infinity);
        dist[src] = 0;

        for (let _ = 0; _ < this.V - 1; _++) {
            for (let u = 0; u < this.V; u++) {
                for (const [v, w] of this.graph[u]) {
                    if (dist[u] !== Infinity && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        for (let u = 0; u < this.V; u++) {
            for (const [v, w] of this.graph[u]) {
                if (dist[u] !== Infinity && dist[u] + w < dist[v]) {
                    return false;
                }
            }
        }

        return dist;
    }
}

function main(): void {
    const g = new Graph(5);
    g.add_edge(0, 1, -1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 2);
    g.add_edge(3, 2, 5);
    g.add_edge(3, 1, 1);
    g.add_edge(4, 3, -3);
    const dist = g.bellman_ford(0);

    if (dist) {
        for (let i = 0; i < g.V; i++) {
            console.log(`${i}\t${dist[i]}`);
        }
    } else {
        console.log('Graph contains negative weight cycle');
    }
}

main();