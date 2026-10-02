class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    addEdge(u, v, w) {
        this.graph[u].push([v, w]);
        this.graph[v].push([u, w]);
    }
}

function minDistance(dist, sptSet) {
    let min = Infinity;
    let min_index = -1;
    for (let v = 0; v < dist.length; v++) {
        if (dist[v] < min && !sptSet[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

function dijkstra(graph, src) {
    let dist = Array(graph.V).fill(Infinity);
    dist[src] = 0;
    let sptSet = Array(graph.V).fill(false);
    for (let count = 0; count < graph.V; count++) {
        let u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (let [v, weight] of graph.graph[u]) {
            if (!sptSet[v] && dist[u] !== Infinity && (dist[u] + weight < dist[v])) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

function main() {
    let g = new Graph(9);
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
    let dist = dijkstra(g, 0);
    for (let node = 0; node < dist.length; node++) {
        console.log(`Distance to node ${node} is ${dist[node]}`);
    }
}

main();