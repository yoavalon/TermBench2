function dfs(graph: { [key: string]: string[] }, start: string, end: string, visited: Set<string> = new Set()): string[] | null {
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const path = dfs(graph, neighbor, end, visited);
            if (path) {
                return [start, ...path];
            }
        }
    }
    return null;
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): number {
    const path = dfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['G'], 'F': ['G'], 'G': [] };
const start_node = 'A';
const end_node = 'G';
const result = shortest_path(graph, start_node, end_node);
console.log(result);