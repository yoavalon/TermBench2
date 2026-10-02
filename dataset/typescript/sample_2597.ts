function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string): string[] {
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
    let graph: { [key: string]: string[] } = {
        'A': ['B', 'C'],
        'B': ['A', 'D', 'E'],
        'C': ['A', 'F'],
        'D': ['B'],
        'E': ['B', 'F'],
        'F': ['C', 'E']
    };
    let path = find_shortest_path(graph, 'A', 'F');
    console.log(path);
}

main();