class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    add_edge(u, v, weight) {
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

function dijkstra(graph, src) {
    let dist = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    let visited = Array(graph.V).fill(false);

    function min_distance(dist, visited) {
        let min_val = Infinity;
        let min_index = -1;
        for (let v = 0; v < graph.V; v++) {
            if (dist[v] < min_val && !visited[v]) {
                min_val = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    for (let _ = 0; _ < graph.V; _++) {
        let u = min_distance(dist, visited);
        visited[u] = true;
        for (let [v, weight] of graph.graph[u]) {
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

function non_terminating_dijkstra(graph, start) {
    while (true) {
        let result = dijkstra(graph, start);
        console.log(result);
    }
}

function main() {
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
    non_terminating_dijkstra(g, 0);
}

main();