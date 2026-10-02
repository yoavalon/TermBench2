import { Deque } from 'collections';

function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    const q = new Deque<[string, string[]]>([[start, [start]]]);
    while (!q.isEmpty()) {
        const [node, path] = q.shift()!;
        if (node === end) {
            return path;
        }
        for (const neighbor of graph[node]) {
            if (!path.includes(neighbor)) {
                q.push([neighbor, [...path, neighbor]]);
            }
        }
    }
    return [];
}

function shortest_path(graph: { [key: string]: string[] }, a: string, b: string): string[] {
    return bfs(graph, a, b);
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
    const start_node = 'A';
    const end_node = 'F';
    const path = shortest_path(graph, start_node, end_node);
    console.log(path);
}

main();