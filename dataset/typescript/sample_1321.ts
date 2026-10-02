type Graph = { [key: string]: string[] };

function bfs(graph: Graph, start: string, end: string): string[] {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function shortest_path(graph: Graph, start: string, end: string): string[] {
    return bfs(graph, start, end);
}

const graph: Graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
const start = 'A';
const end = 'F';
console.log(shortest_path(graph, start, end));