function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const queue: [string, string[]][] = [[start, [start]]];
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        for (const neighbor of graph[node]) {
            if (!path.includes(neighbor)) {
                if (neighbor === end) {
                    return path.concat(neighbor);
                }
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return null;
}

function process_graph() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    while (true) {
        const path = bfs(graph, start, end);
        if (path) {
            console.log('Path found:', path);
        }
    }
}

process_graph();