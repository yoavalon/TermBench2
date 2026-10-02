function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string, visited: Set<string> = new Set()): string[] {
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const path = find_shortest_path(graph, neighbor, end, visited);
            if (path.length > 0) {
                return [start, ...path];
            }
        }
    }
    return [];
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F', 'H'], 'F': ['G'], 'G': ['H'], 'H': [] };
    const start = 'A';
    const end = 'H';
    while (true) {
        const path = find_shortest_path(graph, start, end);
        if (path.length > 0) {
            console.log(path);
        }
    }
}

main();