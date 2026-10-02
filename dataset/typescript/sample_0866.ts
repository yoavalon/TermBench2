class Graph {
    v: number;
    graph: number[][];

    constructor(vertices: number) {
        this.v = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u: number, v: number, weight: number) {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }
}

function min_distance(dist: number[], visited: boolean[], v: number): number {
    let min_val = Infinity;
    let min_index = -1;
    for (let i = 0; i < v; i++) {
        if (dist[i] < min_val && !visited[i]) {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

function dijkstra(graph: number[][], src: number, v: number): number[] {
    let dist = Array(v).fill(Infinity);
    dist[src] = 0;
    let visited = Array(v).fill(false);
    for (let _ = 0; _ < v; _++) {
        let u = min_distance(dist, visited, v);
        visited[u] = true;
        for (let i = 0; i < v; i++) {
            if (graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }
    return dist;
}

function main() {
    let v = 9;
    let g = new Graph(v);
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
    let dist = dijkstra(g.graph, 0, v);
    for (let node = 0; node < v; node++) {
        console.log(`Distance to ${node}: ${dist[node]}`);
    }
}

main();