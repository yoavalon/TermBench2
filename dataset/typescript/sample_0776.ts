function find_shortest_path(graph: { [key: string]: string[] }, start: string, end: string, path: string[] = []): string[] | null {
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    if (!graph[start]) {
        return null;
    }
    let shortest: string[] | null = null;
    for (const node of graph[start]) {
        if (!path.includes(node)) {
            const newpath = find_shortest_path(graph, node, end, path);
            if (newpath) {
                if (!shortest || newpath.length < shortest.length) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

function main() {
    const graph = { 'A': ['B', 'C'], 'B': ['C', 'D'], 'C': ['D'], 'D': ['C'], 'E': ['F'], 'F': ['C'] };
    const start = 'A';
    const end = 'D';
    console.log(find_shortest_path(graph, start, end));
}

main();