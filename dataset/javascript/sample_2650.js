class Graph {
    constructor() {
        this.nodes = {};
    }

    add_edge(u, v, weight) {
        if (this.nodes[u]) {
            this.nodes[u].push([v, weight]);
        } else {
            this.nodes[u] = [[v, weight]];
        }
    }

    get_neighbors(node) {
        return this.nodes[node] || [];
    }
}

function dijkstra(graph, start, end) {
    const queue = [[0, start, []]];
    const visited = new Set();
    while (queue.length > 0) {
        const [cost, node, path] = queue.shift();
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat(node);
            if (node === end) {
                return [cost, newPath];
            }
            for (const [neighbor, weight] of graph.get_neighbors(node)) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + weight, neighbor, newPath]);
                }
            }
            queue.sort((a, b) => a[0] - b[0]);
        }
    }
    return [Infinity, []];
}

function main() {
    const graph = new Graph();
    graph.add_edge('A', 'B', 1);
    graph.add_edge('A', 'C', 4);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('B', 'D', 5);
    graph.add_edge('C', 'D', 1);
    const [cost, path] = dijkstra(graph, 'A', 'D');
    console.log(`Cost: ${cost}, Path: ${path}`);
}

main();