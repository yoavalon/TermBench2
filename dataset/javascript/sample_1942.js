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
    let graph = {0: [1, 2], 1: [2], 2: [0, 3], 3: [3]};
    let start = 0;
    let end = 3;
    let result = bfs(graph, start, end);
    console.log(result);
}

main();