function dfs(graph: { [key: string]: string[] }, node: string, visited: Set<string>, path: string[]): string[] | null {
    visited.add(node);
    path.push(node);
    if (path.length === Object.keys(graph).length) {
        return path;
    }
    for (const neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            const result = dfs(graph, neighbor, new Set(visited), [...path]);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function shortest_path(graph: { [key: string]: string[] }, start: string): string[] {
    const visited = new Set<string>();
    const path = dfs(graph, start, visited, []);
    return path ? path : [];
}

const graph = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
const start = 'A';
console.log(shortest_path(graph, start));