import { PriorityQueue } from 'typescript-collections';

function dijkstra(graph: any, start: string, end: string): [string[], number] {
    const queue = new PriorityQueue<[number, string, string[]]>((a, b) => a[0] - b[0]);
    queue.enqueue([0, start, []]);
    const visited = new Set<string>();
    while (!queue.isEmpty()) {
        const [cost, node, path] = queue.dequeue()!;
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat(node);
            if (node === end) {
                return [newPath, cost];
            }
            for (const neighbor in graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.enqueue([cost + graph[node][neighbor], neighbor, newPath]);
                }
            }
        }
    }
    return [[], 0];
}

function main() {
    const graph = {
        'A': { 'B': 1, 'C': 4 },
        'B': { 'A': 1, 'C': 2, 'D': 5 },
        'C': { 'A': 4, 'B': 2, 'D': 1 },
        'D': { 'B': 5, 'C': 1 }
    };
    const startNode = 'A';
    const endNode = 'D';
    const [path, cost] = dijkstra(graph, startNode, endNode);
    console.log(`Path: ${path}, Cost: ${cost}`);
}

main();