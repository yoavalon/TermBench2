function bfs(graph, start, end) {
    let queue = [[start, [start]]];
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        for (let neighbor of graph[node]) {
            if (!path.includes(neighbor)) {
                if (neighbor === end) {
                    return path.concat(neighbor);
                }
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
}

function process_graph() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start = 'A';
    let end = 'F';
    while (true) {
        let path = bfs(graph, start, end);
        if (path) {
            console.log('Path found:', path);
        }
    }
}
process_graph();