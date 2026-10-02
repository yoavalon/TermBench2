class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    addEdge(u, v, w) {
        this.graph[u].push([v, w]);
        this.graph[v].push([u, w]);
    }

    dijkstra(src) {
        const dist = Array(this.V).fill(Infinity);
        dist[src] = 0;
        const visited = Array(this.V).fill(false);
        while (true) {
            let minDist = Infinity;
            let u = -1;
            for (let i = 0; i < this.V; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }
            if (u === -1) {
                break;
            }
            visited[u] = true;
            for (const [v, weight] of this.graph[u]) {
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
}

function nonTerminatingGraphTraversal() {
    const g = new Graph(10);
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
    while (true) {
        const dist = g.dijkstra(0);
        console.log(dist);
    }
}

function main() {
    nonTerminatingGraphTraversal();
}

main();