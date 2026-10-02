class Graph {
    nodes: string[];
    edges: { [key: string]: { [key: string]: number } };

    constructor(nodes: string[]) {
        this.nodes = nodes;
        this.edges = {};
    }

    add_edge(u: string, v: string, weight: number): void {
        if (!this.edges[u]) {
            this.edges[u] = {};
        }
        this.edges[u][v] = weight;
    }

    get_neighbors(node: string): { [key: string]: number } {
        return this.edges[node] || {};
    }
}

class Dijkstra {
    graph: Graph;
    start: string;
    distances: { [key: string]: number };
    priority_queue: [number, string][];

    constructor(graph: Graph, start: string) {
        this.graph = graph;
        this.start = start;
        this.distances = {};
        this.graph.nodes.forEach(node => {
            this.distances[node] = Infinity;
        });
        this.distances[start] = 0;
        this.priority_queue = [[0, start]];
    }

    extract_min(): string {
        let min_distance = Infinity;
        let min_node = '';
        for (const [node, distance] of this.priority_queue) {
            if (distance < min_distance) {
                min_distance = distance;
                min_node = node;
            }
        }
        const index = this.priority_queue.findIndex(([node, _]) => node === min_node);
        if (index !== -1) {
            this.priority_queue.splice(index, 1);
        }
        return min_node;
    }

    update_distances(current: string, neighbors: [string, number][]): void {
        for (const [neighbor, weight] of neighbors) {
            const new_distance = this.distances[current] + weight;
            if (new_distance < this.distances[neighbor]) {
                this.distances[neighbor] = new_distance;
                this.priority_queue.push([new_distance, neighbor]);
            }
        }
    }

    run(): { [key: string]: number } {
        while (this.priority_queue.length > 0) {
            const current = this.extract_min();
            const neighbors = Object.entries(this.graph.get_neighbors(current)).map(([neighbor, weight]) => [neighbor, weight] as [string, number]);
            this.update_distances(current, neighbors);
        }
        return this.distances;
    }
}

function main(): void {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const graph = new Graph(nodes);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('B', 'D', 5);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('D', 'E', 3);
    const dijkstra = new Dijkstra(graph, 'A');
    const shortest_paths = dijkstra.run();
    console.log(shortest_paths);
}

main();