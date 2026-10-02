import { Deque } from 'collections/deque';

function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const queue = new Deque<[string, string[]]>([[start, [start]]]);
    const visited = new Set<string>();
    while (!queue.isEmpty()) {
        const [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return null;
}

function findShortestPath(graph: { [key: string]: string[] }, start: string, end: string): number {
    const path = bfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
    const start = 'A';
    const end = 'F';
    console.log(findShortestPath(graph, start, end));
}

main();