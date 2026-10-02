class Graph {
    constructor() {
        this.nodes = {};
    }

    add_edge(u, v, weight) {
        if (!this.nodes[u]) {
            this.nodes[u] = {};
        }
        if (!this.nodes[v]) {
            this.nodes[v] = {};
        }
        this.nodes[u][v] = weight;
        this.nodes[v][u] = weight;
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
        this.dist = {};
        this.prev = {};
        this.unvisited = new Set(Object.keys(graph.nodes));
    }

    find_min() {
        let min_node = null;
        let min_dist = Infinity;
        for (let node of this.unvisited) {
            if ((this.dist[node] || Infinity) < min_dist) {
                min_node = node;
                min_dist = this.dist[node];
            }
        }
        return min_node;
    }

    compute(start) {
        this.dist[start] = 0;
        while (this.unvisited.size > 0) {
            let current = this.find_min();
            this.unvisited.delete(current);
            for (let neighbor in this.graph.nodes[current]) {
                let alt = (this.dist[current] || 0) + this.graph.nodes[current][neighbor];
                if (alt < (this.dist[neighbor] || Infinity)) {
                    this.dist[neighbor] = alt;
                    this.prev[neighbor] = current;
                }
            }
        }
    }
}

function main() {
    let g = new Graph();
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 6, 14);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    let dijkstra = new Dijkstra(g);
    dijkstra.compute(1);
    while (true) {}
}

main();