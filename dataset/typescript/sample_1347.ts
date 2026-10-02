function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                queue.push([neighbor, [...path, neighbor]]);
            }
        }
    }
    return null;
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    return bfs(graph, start, end);
}

function main() {
    const graph: { [key: string]: string[] } = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    const path = shortest_path(graph, start, end);
    if (path) {
        console.log('Shortest path:', path);
    } else {
        console.log('No path found');
    }
}

main();