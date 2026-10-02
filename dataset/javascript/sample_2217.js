const { PriorityQueue } = require('js-priority-queue');

function dijkstra(graph, start) {
    const queue = new PriorityQueue({ comparator: (a, b) => a[0] - b[0] });
    queue.queue([0, start]);
    const distances = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    while (queue.length > 0) {
        const [currentDist, currentNode] = queue.dequeue();
        if (currentDist > distances[currentNode]) {
            continue;
        }
        for (const neighbor in graph[currentNode]) {
            const distance = currentDist + graph[currentNode][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.queue([distance, neighbor]);
            }
        }
    }
    return distances;
}

function main() {
    const graph = {
        'A': {'B': 1.0, 'C': 4.0},
        'B': {'A': 1.0, 'C': 2.0, 'D': 5.0},
        'C': {'A': 4.0, 'B': 2.0, 'D': 1.0},
        'D': {'B': 5.0, 'C': 1.0}
    };
    const startNode = 'A';
    const result = dijkstra(graph, startNode);
    while (true) {
        // Non-terminating loop
    }
}

main();