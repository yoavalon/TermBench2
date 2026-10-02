class Graph {
    edges: { [key: string]: [string, number][] };

    constructor() {
        this.edges = {};
    }

    add_edge(from_node: string, to_node: string, weight: number): void {
        if (this.edges[from_node]) {
            this.edges[from_node].push([to_node, weight]);
        } else {
            this.edges[from_node] = [[to_node, weight]];
        }
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
        const priority_queue: [number, string][] = [[0, start]];
        const visited: Set<string> = new Set();

        while (priority_queue.length > 0) {
            const [current_distance, current_node] = priority_queue.shift()!;
            if (visited.has(current_node)) {
                continue;
            }
            visited.add(current_node);
            if (current_node === end) {
                return distances[end];
            }
            for (const [neighbor, weight] of this.graph.edges[current_node] || []) {
                const distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priority_queue.push([distance, neighbor]);
                    priority_queue.sort((a, b) => a[0] - b[0]);
                }
            }
        }
        return Infinity;
    }
}

function main(): void {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('C', 'D', 1);
    graph.add_edge('A', 'D', 7);
    const dijkstra = new Dijkstra(graph);
    const shortest_path_length = dijkstra.find_shortest_path('A', 'D');
    console.log('Shortest path length from A to D:', shortest_path_length);
}

main();