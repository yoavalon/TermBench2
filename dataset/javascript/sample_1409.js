class Graph {
    constructor(nodes) {
        this.nodes = nodes;
        this.edges = {};
        for (let node of nodes) {
            this.edges[node] = [];
        }
    }

    add_edge(node1, node2, weight) {
        this.edges[node1].push([node2, weight]);
        this.edges[node2].push([node1, weight]);
    }
}

function dijkstra(graph, start, end) {
    const queue = [];
    queue.push([0, start, []]);
    const visited = new Set();
    while (queue.length > 0) {
        queue.sort((a, b) => a[0] - b[0]);
        const [cost, node, path] = queue.shift();
        if (node === end) {
            return path.concat(node);
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let [neighbor, weight] of graph.edges[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + weight, neighbor, path.concat(node)]);
                }
            }
        }
    }
    return [];
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const graph = new Graph(nodes);
    graph.add_edge('A', 'B', 1);
    graph.add_edge('B', 'C', 2);
    graph.add_edge('C', 'D', 3);
    graph.add_edge('D', 'E', 4);
    graph.add_edge('E', 'A', 5);
    const path = dijkstra(graph, 'A', 'E');
    console.log(path);
}

main();