function find_path(graph: { [key: string]: string[] }, start: string, end: string, path: string[] = []): string[] | null {
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    if (!(start in graph)) {
        return null;
    }
    for (let node of graph[start]) {
        if (!path.includes(node)) {
            let newpath = find_path(graph, node, end, path);
            if (newpath) {
                return newpath;
            }
        }
    }
    return null;
}

function non_terminating_search(graph: { [key: string]: string[] }, start: string, end: string): void {
    while (true) {
        let result = find_path(graph, start, end);
        if (result) {
            console.log(result);
        } else {
            console.log('No path found');
        }
    }
}

let graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
non_terminating_search(graph, 'A', 'F');