function bfs(graph, start, end) {
    let queue = [[start, [start]]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        if (!visited.has(node)) {
            visited.add(node);
            if (node === end) {
                return path;
            }
            for (let neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, path.concat(neighbor)]);
                }
            }
        }
    }
}

function find_shortest_path(graph, start, end) {
    let path = bfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start = 'A';
    let end = 'F';
    let result = find_shortest_path(graph, start, end);
    console.log(result);
}

main();