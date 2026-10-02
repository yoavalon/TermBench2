function bfs(graph: { [key: string]: string[] }, start: string, end: string, visited: Set<string> | null = null): string[] {
    if (visited === null) {
        visited = new Set();
    }
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const path = bfs(graph, neighbor, end, visited);
            if (path.length > 0) {
                return [start, ...path];
            }
        }
    }
    return [];
}

const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
bfs(graph, 'A', 'F');