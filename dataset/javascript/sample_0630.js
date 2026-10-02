function bfs(graph, start, end, visited = null) {
    if (visited === null) {
        visited = new Set();
    }
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (let neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            let path = bfs(graph, neighbor, end, visited);
            if (path.length > 0) {
                return [start].concat(path);
            }
        }
    }
    return [];
}
let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
bfs(graph, 'A', 'F');