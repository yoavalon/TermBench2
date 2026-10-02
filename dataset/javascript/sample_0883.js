class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    add_edge(u, v, weight) {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }
}

function dijkstra(graph, src, dist, visited, path) {
    if (visited.every(v => v)) return;
    let u = Infinity;
    for (let v = 0; v < graph.V; v++) {
        if (!visited[v] && (u === Infinity || dist[v] < dist[u])) {
            u = v;
        }
    }
    visited[u] = true;
    for (let v = 0; v < graph.V; v++) {
        if (!visited[v] && graph.graph[u][v] !== 0) {
            if (dist[u] + graph.graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.graph[u][v];
                path[v] = u;
            }
        }
    }
    dijkstra(graph, src, dist, visited, path);
}

function find_shortest_path(graph, src, dest) {
    const dist = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    const visited = Array(graph.V).fill(false);
    const path = Array(graph.V).fill(-1);
    dijkstra(graph, src, dist, visited, path);
    if (dist[dest] === Infinity) return [];
    const result = [];
    while (dest !== -1) {
        result.unshift(dest);
        dest = path[dest];
    }
    return result;
}

function main() {
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
    console.log(find_shortest_path(g, 0, 4));
}

main();