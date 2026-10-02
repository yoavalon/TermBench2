function dfs(graph, node, visited, target) {
    if (node === target) {
        return [node];
    }
    visited.add(node);
    for (let neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            let path = dfs(graph, neighbor, visited, target);
            if (path) {
                return [node].concat(path);
            }
        }
    }
    return [];
}

function find_shortest_path(graph, start, target) {
    let visited = new Set();
    return dfs(graph, start, visited, target);
}

let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
let start_node = 'A';
let target_node = 'F';
let path = find_shortest_path(graph, start_node, target_node);
console.log(path);