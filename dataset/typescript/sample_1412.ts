class Graph {
    edges: { [key: string]: { [key: string]: number } } = {};

    add_edge(node1: string, node2: string, weight: number): void {
        if (!this.edges[node1]) {
            this.edges[node1] = {};
        }
        if (!this.edges[node2]) {
            this.edges[node2] = {};
        }
        this.edges[node1][node2] = weight;
        this.edges[node2][node1] = weight;
    }

    get_neighbors(node: string): { [key: string]: number } {
        return this.edges[node] || {};
    }
}

class Dijkstra {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_shortest_path(start: string, end: string): number {
        const distances: { [key: string]: number } = {};
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
                const weight = this.graph.get_neighbors(current)[neighbor];
                const distance = distances[current] + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                }
            }
        }
        return distances[end];
    }
}

function main(): void {
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