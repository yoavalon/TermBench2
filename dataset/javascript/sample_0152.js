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
    return [];
}

function findShortestPath(graph, start, end) {
    return bfs(graph, start, end);
}

if (typeof require !== 'undefined' && require.main === module) {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let startNode = 'A';
    let endNode = 'F';
    let path = findShortestPath(graph, startNode, endNode);
    console.log(path);
}