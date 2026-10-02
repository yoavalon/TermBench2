function bfs(graph, start, end) {
    let queue = [[start, 0]];
    let visited = new Set();
    while (queue.length > 0) {
        let [node, dist] = queue.shift();
        if (node === end) {
            return dist;
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (let neighbor of graph[node]) {
                queue.push([neighbor, dist + 1]);
            }
        }
    }
    return -1;
}

function main() {
    let graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
    let start = 'A';
    let end = 'F';
    console.log(bfs(graph, start, end));
}

main();