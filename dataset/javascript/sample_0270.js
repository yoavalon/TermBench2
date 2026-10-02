class Graph {
    constructor() {
        this.edges = {};
    }

    add_edge(u, v, w) {
        if (this.edges[u]) {
            this.edges[u].push([v, w]);
        } else {
            this.edges[u] = [[v, w]];
        }
    }

    get_neighbors(u) {
        return this.edges[u] || [];
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
    }

    find_shortest_path(start, end) {
        const q = [[0, start, []]];
        const dist = { [start]: 0 };
        const visited = new Set();
        while (q.length > 0) {
            q.sort((a, b) => a[0] - b[0]);
            const [cost, node, path] = q.shift();
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
        }
        return null;
    }
}

function main() {
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