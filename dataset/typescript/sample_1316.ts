import { Deque } from 'collections';

function bfs(graph: { [key: string]: Set<string> }, start: string, end: string): string[] | null {
    const queue = new Deque<[string, string[]]>([[start, [start]]]);
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        visited.add(node);
        for (const neighbor of graph[node].difference(visited)) {
            queue.push([neighbor, [...path, neighbor]]);
        }
    }
    return null;
}

function main() {
    const graph: { [key: string]: Set<string> } = {
        'A': new Set(['B', 'C']),
        'B': new Set(['A', 'D', 'E']),
        'C': new Set(['A', 'F']),
        'D': new Set(['B']),
        'E': new Set(['B', 'F']),
        'F': new Set(['C', 'E'])
    };
    const start_node = 'A';
    const end_node = 'F';
    const result = bfs(graph, start_node, end_node);
    if (result) {
        console.log(result);
    } else {
        console.log('No path found');
    }
}

main();