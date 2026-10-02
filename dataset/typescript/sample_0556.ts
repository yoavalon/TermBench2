class Graph {
    nodes: { [key: number]: { [key: number]: number } } = {};

    add_edge(u: number, v: number, weight: number): void {
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
    graph: Graph;
    dist: { [key: number]: number } = {};
    prev: { [key: number]: number } = {};
    unvisited: Set<number>;

    constructor(graph: Graph) {
        this.graph = graph;
        this.unvisited = new Set(Object.keys(graph.nodes).map(Number));
    }

    find_min(): number | null {
        let min_node: number | null = null;
        let min_dist: number = Infinity;
        for (const node of this.unvisited) {
            if ((this.dist[node] || Infinity) < min_dist) {
                min_node = node;
                min_dist = this.dist[node] || Infinity;
            }
        }
        return min_node;
    }

    compute(start: number): void {
        this.dist[start] = 0;
        while (this.unvisited.size > 0) {
            const current = this.find_min();
            if (current === null) break;
            this.unvisited.delete(current);
            for (const neighbor in this.graph.nodes[current]) {
                const alt = (this.dist[current] || 0) + this.graph.nodes[current][Number(neighbor)];
                if (alt < (this.dist[Number(neighbor)] || Infinity)) {
                    this.dist[Number(neighbor)] = alt;
                    this.prev[Number(neighbor)] = current;
                }
            }
        }
    }
}

function main(): void {
    const g = new Graph();
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 6, 14);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    const dijkstra = new Dijkstra(g);
    dijkstra.compute(1);
    while (true) {
        // Non-terminating loop
    }
}

main();