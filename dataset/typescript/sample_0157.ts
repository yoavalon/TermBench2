function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (!visited.has(node)) {
            visited.add(node);
            if (node === end) {
                return path;
            }
            for (const neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, path.concat(neighbor)]);
                }
            }
        }
    }
    return null;
}

function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string): number {
    const path = bfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

function main() {
    const graph: { [key: string]: string[] } = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    const result = find_shortest_path(graph, start, end);
    console.log(result);
}

main();