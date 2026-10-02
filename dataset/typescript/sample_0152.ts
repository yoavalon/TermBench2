function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] {
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
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function findShortestPath(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    return bfs(graph, start, end);
}

if (require.main === module) {
    const graph: { [key: string]: string[] } = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const startNode = 'A';
    const endNode = 'F';
    const path = findShortestPath(graph, startNode, endNode);
    console.log(path);
}