import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: { [key: string]: { [key: string]: number } }, start: string, end: string): number {
    const dist: { [key: string]: number } = {};
    for (const node in graph) {
        dist[node] = Infinity;
    }
    dist[start] = 0;
    const queue = new PriorityQueue<[number, string]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start]);
    while (!queue.isEmpty()) {
        const [current_dist, current_node] = queue.dequeue()!;
        if (current_dist > dist[current_node]) {
            continue;
        }
        for (const neighbor in graph[current_node]) {
            const weight = graph[current_node][neighbor];
            const distance = current_dist + weight;
            if (distance < dist[neighbor]) {
                dist[neighbor] = distance;
                queue.enqueue([distance, neighbor]);
            }
        }
    }
    return dist[end];
}

function main() {
    const graph = {
        'A': { 'B': 1, 'C': 4 },
        'B': { 'A': 1, 'C': 2, 'D': 5 },
        'C': { 'A': 4, 'B': 2, 'D': 1 },
        'D': { 'B': 5, 'C': 1 }
    };
    const start = 'A';
    const end = 'D';
    const result = dijkstra(graph, start, end);
    console.log(result);
}

main();