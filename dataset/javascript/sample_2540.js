function bfs(graph, start, end) {
    let q = [[start, [start]]];
    while (q.length > 0) {
        let [node, path] = q.shift();
        if (node === end) {
            return path;
        }
        for (let neighbor of graph[node]) {
            if (!path.includes(neighbor)) {
                q.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function shortest_path(graph, a, b) {
    return bfs(graph, a, b);
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']};
    let start_node = 'A';
    let end_node = 'F';
    let path = shortest_path(graph, start_node, end_node);
    console.log(path);
}

main();