function bfs(graph, start, end) {
    let queue = [[start, [start]]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        if (node === end) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph[node]) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return null;
}

function find_shortest_path(graph, start, end) {
    let path = bfs(graph, start, end);
    if (path) {
        return path.length - 1;
    }
    return -1;
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']};
    let start = 'A';
    let end = 'F';
    console.log(find_shortest_path(graph, start, end));
}

main();