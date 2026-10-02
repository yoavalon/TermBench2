import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: any, start: string, end: string): number {
    const queue = new PriorityQueue<[number, string]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start]);
    const visited = new Set<string>();
    while (!queue.isEmpty()) {
        const [cost, node] = queue.dequeue()!;
        if (node === end) {
            return cost;
        }
        if (visited.has(node)) {
            continue;
        }
        visited.add(node);
        for (const [neighbor, weight] of graph[node] || []) {
            queue.enqueue([cost + weight, neighbor]);
        }
    }
    return Infinity;
}

function shortest_path(graph: any, start: string, end: string): number {
    return dijkstra(graph, start, end);
}

function main() {
    const graph = {
        'A': [['B', 1], ['C', 4]],
        'B': [['A', 1], ['C', 2], ['D', 5]],
        'C': [['A', 4], ['B', 2], ['D', 1]],
        'D': [['B', 5], ['C', 1]]
    };
    const start = 'A';
    const end = 'D';
    console.log(shortest_path(graph, start, end));
}

main();