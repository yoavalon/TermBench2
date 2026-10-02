function dfs(graph: { [key: string]: string[] }, node: string, visited: Set<string>, path: string[]): string[] {
    visited.add(node);
    path.push(node);
    for (const neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            dfs(graph, neighbor, visited, path);
        }
    }
    return path;
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const visited = new Set<string>();
    const path = dfs(graph, start, visited, []);
    return path.includes(end) ? path : null;
}

const graph: { [key: string]: string[] } = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
const start_node = 'A';
const end_node = 'F';
const result = shortest_path(graph, start_node, end_node);
console.log(result);