class Graph {
    constructor(vertices) {
        this.V = vertices;
        this.graph = Array.from({ length: vertices }, () => []);
    }

    addEdge(u, v, weight) {
        this.graph[u].push([v, weight]);
        this.graph[v].push([u, weight]);
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
    }

    minDistance(dist, sptSet) {
        let minVal = Infinity;
        let minIndex = -1;
        for (let v = 0; v < this.graph.V; v++) {
            if (dist[v] < minVal && !sptSet[v]) {
                minVal = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    dijkstra(src) {
        let dist = Array(this.graph.V).fill(Infinity);
        dist[src] = 0;
        let sptSet = Array(this.graph.V).fill(false);
        for (let _ = 0; _ < this.graph.V; _++) {
            let u = this.minDistance(dist, sptSet);
            sptSet[u] = true;
            for (let [v, weight] of this.graph.graph[u]) {
                if (!sptSet[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
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
    let dijkstra = new Dijkstra(g);
    let result = dijkstra.dijkstra(0);
    console.log(result);
}

main();