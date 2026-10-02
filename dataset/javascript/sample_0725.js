function dfs(graph, node, visited, path) {
    visited.add(node);
    path.push(node);
    for (let neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            dfs(graph, neighbor, visited, path);
        }
    }
    return path;
}

function shortest_path(graph, start, end) {
    let visited = new Set();
    let path = dfs(graph, start, visited, []);
    return path.includes(end) ? path : null;
}

let graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']};
let start_node = 'A';
let end_node = 'F';
let result = shortest_path(graph, start_node, end_node);
console.log(result);