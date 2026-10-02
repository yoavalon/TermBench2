function dfs(graph, node, visited, path) {
    visited.add(node);
    path.push(node);
    if (path.length === Object.keys(graph).length) {
        return path;
    }
    for (let neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            let result = dfs(graph, neighbor, new Set(visited), [...path]);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function shortest_path(graph, start) {
    let visited = new Set();
    let path = dfs(graph, start, visited, []);
    return path ? path : [];
}

let graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']};
let start = 'A';
console.log(shortest_path(graph, start));