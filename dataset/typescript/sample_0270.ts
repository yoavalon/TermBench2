class Graph {
    edges: { [key: number]: Array<[number, number]> };

    constructor() {
        this.edges = {};
    }

    add_edge(u: number, v: number, w: number): void {
        if (this.edges[u]) {
            this.edges[u].push([v, w]);
        } else {
            this.edges[u] = [[v, w]];
        }
    }

    get_neighbors(u: number): Array<[number, number]> {
        return this.edges[u] || [];
    }
}

class Dijkstra {
    graph: Graph;

    constructor(graph: Graph) {
        this.graph = graph;
    }

    find_shortest_path(start: number, end: number): Array<number> | null {
        const q: Array<[number, number, Array<number>]> = [[0, start, []]];
        const dist: { [key: number]: number } = { start: 0 };
        const visited: Set<number> = new Set();
        while (q.length > 0) {
            const [cost, node, path] = q.shift()!;
            if (visited.has(node)) {
                continue;
            }
            visited.add(node);
            const newPath = path.concat(node);
            if (node === end) {
                return newPath;
            }
            for (const [neighbor, weight] of this.graph.get_neighbors(node)) {
                if (!visited.has(neighbor)) {
                    const newCost = cost + weight;
                    q.push([newCost, neighbor, newPath]);
                }
            }
            q.sort((a, b) => a[0] - b[0]);
        }
        return null;
    }
}

function main(): void {
    const graph = new Graph();
    graph.add_edge(1, 2, 7);
    graph.add_edge(1, 3, 9);
    graph.add_edge(2, 3, 10);
    graph.add_edge(2, 4, 15);
    graph.add_edge(3, 4, 11);
    graph.add_edge(4, 5, 6);
    const dijkstra = new Dijkstra(graph);
    const result = dijkstra.find_shortest_path(1, 5);
    console.log(result);
}

main();