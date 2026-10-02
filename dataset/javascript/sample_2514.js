function bfsShortestPath(graph, start, goal) {
    let queue = [[start, [start]]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, path] = queue.shift();
        if (node === goal) {
            return path;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([neighbor, path.concat(neighbor)]);
                }
            }
        }
    }
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F'], 'F': ['G'], 'G': []};
    let startNode = 'A';
    let goalNode = 'G';
    let result = bfsShortestPath(graph, startNode, goalNode);
    console.log(result);
}

main();