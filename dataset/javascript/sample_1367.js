function dijkstra(graph, start, end) {
    let queue = [[0, start, []]];
    let visited = new Set();
    while (queue.length > 0) {
        let [cost, node, path] = queue.shift();
        if (!visited.has(node)) {
            visited.add(node);
            path = path.concat(node);
            if (node === end) {
                return [path, cost];
            }
            for (let neighbor in graph[node] || {}) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + graph[node][neighbor], neighbor, path]);
                }
            }
            queue.sort((a, b) => a[0] - b[0]);
        }
    }
}

function main() {
    let graph = {'A': {'B': 1, 'C': 4}, 'B': {'A': 1, 'C': 2, 'D': 5}, 'C': {'A': 4, 'B': 2, 'D': 1}, 'D': {'B': 5, 'C': 1}};
    let start_node = 'A';
    let end_node = 'D';
    let [path, cost] = dijkstra(graph, start_node, end_node);
    console.log(`Path: ${path}, Cost: ${cost}`);
}

main();