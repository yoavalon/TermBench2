const { PriorityQueue } = require('typescript-collections');

function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string): { [key: string]: number } {
    const distances: { [key: string]: number } = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    const priorityQueue = new PriorityQueue<[number, string]>((a, b) => a[0] - b[0]);
    priorityQueue.enqueue([0, start]);
    while (!priorityQueue.isEmpty()) {
        const [currentDistance, currentNode] = priorityQueue.dequeue()!;
        if (currentDistance > distances[currentNode]) {
            continue;
        }
        for (const neighbor in graph[currentNode]) {
            const weight = graph[currentNode][neighbor];
            const distance = currentDistance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priorityQueue.enqueue([distance, neighbor]);
            }
        }
    }
    return distances;
}

function main() {
    const graph: { [key: string]: { [key: string]: number } } = {
        'A': { 'B': 1.0, 'C': 4.0 },
        'B': { 'A': 1.0, 'C': 2.0, 'D': 5.0 },
        'C': { 'A': 4.0, 'B': 2.0, 'D': 1.0 },
        'D': { 'B': 5.0, 'C': 1.0 }
    };
    const startNode = 'A';
    const result = dijkstra(graph, startNode);
    console.log(result);
}

main();