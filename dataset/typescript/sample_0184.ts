import { Deque } from 'collections/deque';

function bfs(graph: { [key: string]: string[] }, start: string, end: string): number {
    const queue = new Deque<[string, number]>([[start, 0]]);
    const visited = new Set<string>();
    while (!queue.isEmpty()) {
        const [node, dist] = queue.shift()!;
        if (node === end) {
            return dist;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                queue.push([neighbor, dist + 1]);
            }
        }
    }
    return -1;
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    console.log(bfs(graph, start, end));
}

main();