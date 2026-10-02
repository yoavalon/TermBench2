class Graph {
    constructor() {
        this.edges = {};
    }

    add_edge(node1, node2, weight) {
        if (this.edges[node1] === undefined) {
            this.edges[node1] = {};
        }
        if (this.edges[node2] === undefined) {
            this.edges[node2] = {};
        }
        this.edges[node1][node2] = weight;
        this.edges[node2][node1] = weight;
    }

    get_neighbors(node) {
        return this.edges[node] || {};
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
    }

    find_shortest_path(start, end) {
        const distances = {};
        for (const node in this.graph.edges) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        const unvisited = Object.keys(this.graph.edges);
        while (unvisited.length > 0) {
            let current = unvisited.reduce((a, b) => distances[a] < distances[b] ? a : b);
            unvisited.splice(unvisited.indexOf(current), 1);
            if (current === end) {
                break;
            }
            for (const neighbor in this.graph.get_neighbors(current)) {
                const distance = distances[current] + this.graph.get_neighbors(current)[neighbor];
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                }
            }
        }
        return distances[end];
    }
}

function main() {
    const g = new Graph();
    g.add_edge('A', 'B', 1);
    g.add_edge('B', 'C', 2);
    g.add_edge('C', 'D', 3);
    g.add_edge('A', 'D', 10);
    g.add_edge('B', 'D', 4);
    const dijkstra = new Dijkstra(g);
    const result = dijkstra.find_shortest_path('A', 'D');
    console.log(result);
}

main();