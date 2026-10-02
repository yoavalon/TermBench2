function dfs(graph: { [key: string]: string[] }, start: string, end: string, path: string[], visited: Set<string>): string[] | null {
    path.push(start);
    visited.add(start);
    if (start === end) {
        return path;
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const result = dfs(graph, neighbor, end, path.slice(), visited);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    return dfs(graph, start, end, [], new Set());
}

const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
const path = find_shortest_path(graph, 'A', 'F');
if (path) {
    console.log('Path found:', path);
} else {
    console.log('No path found');
}