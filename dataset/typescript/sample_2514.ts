function bfsShortestPath(graph: { [key: string]: string[] }, start: string, goal: string): string[] {
    const queue: [string, string[]][] = [[start, [start]]];
    const visited: Set<string> = new Set();
    while (queue.length > 0) {
        const [node, path] = queue.shift()!;
        if (node === goal) {
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
    return [];
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F'], 'F': ['G'], 'G': [] };
    const startNode = 'A';
    const goalNode = 'G';
    const result = bfsShortestPath(graph, startNode, goalNode);
    console.log(result);
}

main();