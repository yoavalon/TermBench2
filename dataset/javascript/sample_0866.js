class Graph {
    constructor(vertices) {
        this.v = vertices;
        this.graph = Array.from({ length: vertices }, () => Array(vertices).fill(0));
    }

    addEdge(u, v, weight) {
        this.graph[u][v] = weight;
        this.graph[v][u] = weight;
    }
}

function minDistance(dist, visited, v) {
    let minVal = Infinity;
    let minIndex = -1;
    for (let i = 0; i < v; i++) {
        if (dist[i] < minVal && !visited[i]) {
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

function dijkstra(graph, src, v) {
    const dist = Array(v).fill(Infinity);
    dist[src] = 0;
    const visited = Array(v).fill(false);
    for (let _ = 0; _ < v; _++) {
        const u = minDistance(dist, visited, v);
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
    const v = 9;
    const g = new Graph(v);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    const dist = dijkstra(g.graph, 0, v);
    for (let node = 0; node < v; node++) {
        console.log(`Distance to ${node}: ${dist[node]}`);
    }
}

main();