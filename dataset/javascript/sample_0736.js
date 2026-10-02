function dfs(graph, node, visited, path) {
    if (!visited.has(node)) {
        visited.add(node);
        path.push(node);
        for (let neighbor of graph[node]) {
            dfs(graph, neighbor, visited, path);
        }
    }
    return path;
}

function shortest_path(graph, start, end) {
    let visited = new Set();
    let path = dfs(graph, start, visited, []);
    return path.includes(end) ? path : [];
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start = 'A';
    let end = 'F';
    let result = shortest_path(graph, start, end);
    console.log(result);
}

main();