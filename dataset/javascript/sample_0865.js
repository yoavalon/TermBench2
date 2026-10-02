class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    addEdge(u, v, weight) {
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }

    dijkstra(start) {
        const distance = new Array(this.V).fill(Infinity);
        distance[start] = 0;
        const visited = new Array(this.V).fill(false);

        const minDistance = (dist, visited) => {
            let minDist = Infinity;
            let minIndex = -1;
            for (let v = 0; v < this.V; v++) {
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    minIndex = v;
                }
            }
            return minIndex;
        };

        for (let _ = 0; _ < this.V; _++) {
            const u = minDistance(distance, visited);
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

function main() {
    const g = new Graph(9);
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
    const startVertex = 0;
    const distances = g.dijkstra(startVertex);
    for (let i = 0; i < g.V; i++) {
        console.log(`Distance from ${startVertex} to ${i} is ${distances[i]}`);
    }
}

main();