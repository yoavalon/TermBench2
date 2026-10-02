function dfs(graph, node, visited, path, paths) {
    visited.add(node);
    path.push(node);
    if (graph[node].length === 0) {
        paths.push([...path]);
    }
    for (let neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            dfs(graph, neighbor, visited, path, paths);
        }
    }
    path.pop();
    visited.delete(node);
}

function shortest_path(graph, start, end) {
    let paths = [];
    dfs(graph, start, new Set(), [], paths);
    let min_length = Infinity;
    let best_path = null;
    for (let path of paths) {
        if (path[path.length - 1] === end && path.length < min_length) {
            min_length = path.length;
            best_path = path;
        }
    }
    return best_path;
}

let graph = {'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': []};
let start_node = 'A';
let end_node = 'D';
console.log(shortest_path(graph, start_node, end_node));