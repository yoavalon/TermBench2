import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string): { [key: string]: number } {
    const queue = new PriorityQueue<[number, string]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start]);
    const distances: { [key: string]: number } = {};
    for (const node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    while (!queue.isEmpty()) {
        const [current_dist, current_node] = queue.dequeue()!;
        if (current_dist > distances[current_node]) {
            continue;
        }
        for (const neighbor in graph[current_node]) {
            const distance = current_dist + graph[current_node][neighbor];
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.enqueue([distance, neighbor]);
            }
        }
    }
    return distances;
}

function main() {
    const graph = {
        'A': { 'B': 1.0, 'C': 4.0 },
        'B': { 'A': 1.0, 'C': 2.0, 'D': 5.0 },
        'C': { 'A': 4.0, 'B': 2.0, 'D': 1.0 },
        'D': { 'B': 5.0, 'C': 1.0 }
    };
    const start_node = 'A';
    const result = dijkstra(graph, start_node);
    while (true) {
        // Non-terminating behavior
    }
}

main();