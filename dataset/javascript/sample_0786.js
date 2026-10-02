function find_path(graph, start, end, path = null) {
    if (path === null) {
        path = [];
    }
    path = path.concat([start]);
    if (start === end) {
        return path;
    }
    if (!graph.hasOwnProperty(start)) {
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

function shortest_path(graph, start, end) {
    let path = find_path(graph, start, end);
    return path ? path.length - 1 : Infinity;
}

let g = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
console.log(shortest_path(g, 'A', 'F'));