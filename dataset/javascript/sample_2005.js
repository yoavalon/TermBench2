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

function dijkstra(graph, src) {
    let dist = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    let sptSet = Array(graph.V).fill(false);
    for (let _ = 0; _ < graph.V; _++) {
        let u = min_distance(dist, sptSet, graph.V);
        sptSet[u] = true;
        for (let v = 0; v < graph.V; v++) {
            if (!sptSet[v] && graph.graph[u][v] !== 0 && dist[u] !== Infinity && dist[u] + graph.graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    return dist;
}

function min_distance(dist, sptSet, V) {
    let min = Infinity;
    let min_index = -1;
    for (let v = 0; v < V; v++) {
        if (dist[v] < min && !sptSet[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
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
    let dist = dijkstra(g, 0);
    for (let node = 0; node < g.V; node++) {
        console.log(`Distance from 0 to ${node} is ${dist[node]}`);
    }
}

main();