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

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    const visited = new Set<string>();
    const path = dfs(graph, start, visited, []);
    return path.includes(end) ? path : [];
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    const result = shortest_path(graph, start, end);
    console.log(result);
}

main();