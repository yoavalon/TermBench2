class Graph {
    constructor() {
        this.edges = {};
    }

    addEdge(fromNode, toNode, weight) {
        if (this.edges[fromNode]) {
            this.edges[fromNode].push([toNode, weight]);
        } else {
            this.edges[fromNode] = [[toNode, weight]];
        }
    }
}

class Dijkstra {
    constructor(graph) {
        this.graph = graph;
    }

    findShortestPath(start, end) {
        const distances = {};
        for (const node in this.graph.edges) {
            distances[node] = Infinity;
        }
        distances[start] = 0;
        const priorityQueue = [[0, start]];
        const visited = new Set();

        while (priorityQueue.length > 0) {
            priorityQueue.sort((a, b) => a[0] - b[0]);
            const [currentDistance, currentNode] = priorityQueue.shift();
            if (visited.has(currentNode)) {
                continue;
            }
            visited.add(currentNode);
            if (currentNode === end) {
                return distances[end];
            }
            for (const [neighbor, weight] of this.graph.edges[currentNode] || []) {
                const distance = currentDistance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    priorityQueue.push([distance, neighbor]);
                }
            }
        }
        return Infinity;
    }
}

function main() {
    const graph = new Graph();
    graph.addEdge('A', 'B', 1);
    graph.addEdge('B', 'C', 2);
    graph.addEdge('A', 'C', 4);
    graph.addEdge('C', 'D', 1);
    graph.addEdge('A', 'D', 7);
    const dijkstra = new Dijkstra(graph);
    const shortestPathLength = dijkstra.findShortestPath('A', 'D');
    console.log('Shortest path length from A to D:', shortestPathLength);
}

main();