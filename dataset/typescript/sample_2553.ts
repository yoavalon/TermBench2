function bfs(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    const queue: [string, string[]][] = [[start, [start]]];
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        for (const neighbor of graph[node]) {
            if (neighbor === end) {
                return path.concat(neighbor);
            } else if (!path.includes(neighbor)) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return null;
}

function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] | null {
    return bfs(graph, start, end);
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    const start = 'A';
    const end = 'F';
    const path = find_shortest_path(graph, start, end);
    if (path) {
        console.log(path.join(' -> '));
    } else {
        console.log('No path found');
    }
}

main();