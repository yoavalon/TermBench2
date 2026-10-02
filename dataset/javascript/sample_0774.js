function dfs(graph, start, end, visited = new Set()) {
    visited.add(start);
    if (start === end) {
        return [start];
    }
    for (let neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            let path = dfs(graph, neighbor, end, visited);
            if (path) {
                return [start, ...path];
            }
        }
    }
    return null;
}

function shortest_path(graph, start, end) {
    let path = dfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

let graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': ['G'],
    'E': ['G'],
    'F': ['G'],
    'G': []
};
let start_node = 'A';
let end_node = 'G';
let result = shortest_path(graph, start_node, end_node);
console.log(result);