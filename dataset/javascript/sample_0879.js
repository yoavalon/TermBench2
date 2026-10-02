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

class ShortestPath {
    constructor(graph) {
        this.graph = graph;
    }

    min_distance(dist, sptSet) {
        let min = Infinity;
        let min_index = -1;
        for (let v = 0; v < this.graph.V; v++) {
            if (dist[v] < min && !sptSet[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    dijkstra(src) {
        let dist = Array(this.graph.V).fill(Infinity);
        dist[src] = 0;
        let sptSet = Array(this.graph.V).fill(false);
        for (let count = 0; count < this.graph.V; count++) {
            let u = this.min_distance(dist, sptSet);
            sptSet[u] = true;
            for (let [v, weight] of this.graph.graph[u]) {
                if (!sptSet[v] && dist[u] !== Infinity && (dist[u] + weight < dist[v])) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
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
    let sp = new ShortestPath(g);
    console.log(sp.dijkstra(0));
}

main();