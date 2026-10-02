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
    let path = [];
    dfs(graph, start, visited, path);
    if (path.includes(end)) {
        return path.indexOf(end);
    }
    return -1;
}

let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
let start_node = 'A';
let end_node = 'F';
let result = shortest_path(graph, start_node, end_node);
console.log(result);