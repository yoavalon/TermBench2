function dfs(graph, start, end, path, visited) {
    path.push(start);
    visited.add(start);
    if (start === end) {
        return path;
    }
    for (let neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            let result = dfs(graph, neighbor, end, [...path], visited);
            if (result) {
                return result;
            }
        }
    }
    return null;
}

function findShortestPath(graph, start, end) {
    return dfs(graph, start, end, [], new Set());
}

let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
let path = findShortestPath(graph, 'A', 'F');
if (path) {
    console.log('Path found:', path);
} else {
    console.log('No path found');
}