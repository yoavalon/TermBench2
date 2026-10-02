function graphTraversal(graph: { [key: string]: string[] }, start: string, end: string): string[] {
    let queue: [string, string[]][] = [[start, [start]]];
    let visited: Set<string> = new Set();
    while (queue.length > 0) {
        let [node, path] = queue.shift()!;
        if (node === end) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph[node]) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function main() {
    let graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
    console.log(graphTraversal(graph, 'A', 'F'));
}

main();