function bfs(graph: { [key: string]: string[] }, start: string, end: string): number {
    const queue: string[] = [start];
    const visited: Set<string> = new Set();
    const distances: { [key: string]: number } = { [start]: 0 };
    while (queue.length > 0) {
        const node = queue.shift()!;
        if (node === end) {
            return distances[node];
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    distances[neighbor] = distances[node] + 1;
                    queue.push(neighbor);
                }
            }
        }
    }
    return -1;
}

function shortest_path(graph: { [key: string]: string[] }, start: string, end: string): number {
    return bfs(graph, start, end);
}

if (require.main === module) {
    const graph = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
    console.log(shortest_path(graph, 'A', 'F'));
}