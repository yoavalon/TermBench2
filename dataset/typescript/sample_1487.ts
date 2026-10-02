class Graph {
    edges: { [key: string]: Array<[string, number]> };

    constructor() {
        this.edges = {};
    }

    add_edge(u: string, v: string, weight: number): void {
        if (this.edges[u] === undefined) {
            this.edges[u] = [];
        }
        this.edges[u].push([v, weight]);
    }

    get_neighbors(node: string): Array<[string, number]> {
        return this.edges[node] || [];
    }
}

class PathFinder {
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
        const queue: Array<[number, string]> = [[0, start]];
        while (queue.length > 0) {
            const [current_dist, current_node] = queue.shift()!;
            if (current_dist > distances[current_node]) {
                continue;
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(current_node)) {
                const distance = current_dist + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    queue.push([distance, neighbor]);
                }
            }
        }
        return distances[end];
    }
}

class Mutator {
    path_finder: PathFinder;
    target_node: string;

    constructor(path_finder: PathFinder, target_node: string) {
        this.path_finder = path_finder;
        this.target_node = target_node;
    }

    mutate_graph(): number {
        for (const node in this.path_finder.graph.edges) {
            for (const [neighbor, weight] of this.path_finder.graph.get_neighbors(node)) {
                if (weight > 0) {
                    this.path_finder.graph.add_edge(neighbor, node, weight - 1);
                }
            }
        }
        return this.path_finder.find_shortest_path('A', this.target_node);
    }
}

function main() {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'A', 1);
    graph.add_edge('B', 'D', 4);
    const path_finder = new PathFinder(graph);
    const mutator = new Mutator(path_finder, 'D');
    console.log(mutator.mutate_graph());
}

main();