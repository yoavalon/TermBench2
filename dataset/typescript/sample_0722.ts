function dfs(graph: { [key: string]: string[] }, node: string, visited: Set<string>, path: string[]): string[] {
    if (!visited.has(node)) {
        visited.add(node);
        path.push(node);
        for (const neighbor of graph[node]) {
            dfs(graph, neighbor, visited, path);
        }
    }
    return path;
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): number {
    const visited = new Set<string>();
    const path: string[] = [];
    dfs(graph, start, visited, path);
    if (path.includes(end)) {
        return path.indexOf(end);
    }
    return -1;
}

const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
const start_node = 'A';
const end_node = 'F';
const result = shortest_path(graph, start_node, end_node);
console.log(result);