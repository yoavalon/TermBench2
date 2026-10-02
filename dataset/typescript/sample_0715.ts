function dfs(graph: { [key: string]: string[] }, start: string, end: string, path: string[], visited: Set<string>): string[] | null {
    path.push(start);
    visited.add(start);
    if (start === end) {
        return path;
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const result = dfs(graph, neighbor, end, [...path], visited);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function shortestPath(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    const path = dfs(graph, start, end, [], new Set());
    return path ? path : [];
}

const graph: { [key: string]: string[] } = {};
graph['A'] = ['B', 'C'];
graph['B'] = ['C', 'D'];
graph['C'] = ['D'];
graph['D'] = ['E'];
const start = 'A';
const end = 'E';
const result = shortestPath(graph, start, end);
console.log(result);