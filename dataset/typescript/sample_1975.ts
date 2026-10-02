import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: any, start: string, end: string): [number, string[]] {
    const queue = new PriorityQueue<[number, string, string[]]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start, []]);
    const visited = new Set<string>();
    while (!queue.isEmpty()) {
        const [cost, node, path] = queue.dequeue()!;
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat(node);
            if (node === end) {
                return [cost, newPath];
            }
            for (const [neighbor, weight] of graph[node] || []) {
                if (!visited.has(neighbor)) {
                    queue.enqueue([cost + weight, neighbor, newPath]);
                }
            }
        }
    }
    return [Infinity, []];
}

function main() {
    const graph = {
        'A': [['B', 1.5], ['C', 2.3]],
        'B': [['C', 0.9], ['D', 3.2]],
        'C': [['D', 1.7]],
        'D': []
    };
    const start = 'A';
    const end = 'D';
    const result = dijkstra(graph, start, end);
    console.log(result);
}

main();