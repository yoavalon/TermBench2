class Graph {
    constructor() {
        this.nodes = {};
    }

    addNode(node) {
        if (!this.nodes[node]) {
            this.nodes[node] = [];
        }
    }

    addEdge(fromNode, toNode, weight) {
        if (this.nodes[fromNode]) {
            this.nodes[fromNode].push([toNode, weight]);
        }
    }
}

function dijkstra(graph, start, end) {
    const distances = {};
    for (const node in graph.nodes) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const priorityQueue = [[0, start]];

    while (priorityQueue.length > 0) {
        const [currentDistance, currentNode] = priorityQueue.shift();
        if (currentDistance > distances[currentNode]) {
            continue;
        }
        for (const [neighbor, weight] of graph.nodes[currentNode]) {
            const distance = currentDistance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priorityQueue.push([distance, neighbor]);
                priorityQueue.sort((a, b) => a[0] - b[0]);
            }
        }
    }
    return distances[end];
}

function main() {
    const graph = new Graph();
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 12);
    graph.addEdge(3, 4, 10);
    console.log(dijkstra(graph, 1, 4));
}

main();