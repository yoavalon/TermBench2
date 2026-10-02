function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited: Set<string> = new Set();
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
    return [];
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const path = bfs(graph, 'A', 'F');
    console.log(path);
}

main();