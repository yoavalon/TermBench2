function dfs(graph: { [key: string]: string[] }, node: string, visited: Set<string>, path: string[], paths: string[][]) {
    visited.add(node);
    path.push(node);
    if (graph[node].length === 0) {
        paths.push([...path]);
    }
    for (const neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            dfs(graph, neighbor, visited, path, paths);
        }
    }
    path.pop();
    visited.delete(node);
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const paths: string[][] = [];
    dfs(graph, start, new Set(), [], paths);
    let min_length = Infinity;
    let best_path: string[] | null = null;
    for (const path of paths) {
        if (path[path.length - 1] === end && path.length < min_length) {
            min_length = path.length;
            best_path = path;
        }
    }
    return best_path;
}

const graph: { [key: string]: string[] } = { 'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': [] };
const start_node = 'A';
const end_node = 'D';
console.log(shortest_path(graph, start_node, end_node));