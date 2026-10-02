import * as math from 'mathjs';

class Graph {
    edges: { [key: string]: { [key: string]: number } };

    constructor() {
        this.edges = {};
    }

    add_edge(u: string, v: string, weight: number) {
        if (!this.edges[u]) {
            this.edges[u] = {};
        }
        this.edges[u][v] = weight;
    }
}

class Dijkstra {
    graph: Graph;
    distances: { [key: string]: number };
    previous: { [key: string]: string | null };

    constructor(graph: Graph) {
        this.graph = graph;
        this.distances = {};
        this.previous = {};
    }

    compute(start: string) {
        const unvisited = new Set<string>(Object.keys(this.graph.edges));
        for (const node of unvisited) {
            this.distances[node] = math.inf;
        }
        this.distances[start] = 0;
        while (unvisited.size > 0) {
            let current = Array.from(unvisited).reduce((a, b) => this.distances[a] < this.distances[b] ? a : b);
            unvisited.delete(current);
            for (const [neighbor, weight] of Object.entries(this.graph.edges[current] || {})) {
                const distance = this.distances[current] + weight;
                if (distance < this.distances[neighbor]) {
                    this.distances[neighbor] = distance;
                    this.previous[neighbor] = current;
                }
            }
        }
    }

    shortest_path(start: string, end: string): string[] {
        const path: string[] = [];
        while (end !== null) {
            path.push(end);
            end = this.previous[end] || null;
        }
        return path.reverse();
    }
}

function main() {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1.0);
    graph.add_edge('A', 'C', 4.0);
    graph.add_edge('B', 'C', 2.0);
    graph.add_edge('B', 'D', 5.0);
    graph.add_edge('C', 'D', 1.0);
    const dijkstra = new Dijkstra(graph);
    dijkstra.compute('A');
    const path = dijkstra.shortest_path('A', 'D');
    console.log('Shortest path:', path);
}

main();