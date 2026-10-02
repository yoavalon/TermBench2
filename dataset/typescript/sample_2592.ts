type Graph = { [key: string]: string[] };

function bfs_shortest_path(graph: Graph, start: string, end: string): string[] | null {
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
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, path.concat(neighbor)]);
                }
            }
        }
    }
    return null;
}

function main() {
    const graph: Graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    const path = bfs_shortest_path(graph, start, end);
    if (path) {
        console.log(path.join(' -> '));
    } else {
        console.log('No path found');
    }
}

main();