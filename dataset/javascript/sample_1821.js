function find_shortest_path(graph, start, end) {
    let queue = [[start, 0, new Set([start])]];
    while (queue.length > 0) {
        let [node, cost, visited] = queue.shift();
        if (node === end) {
            return cost;
        }
        for (let neighbor in graph[node] || {}) {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, cost + graph[node][neighbor], new Set([...visited, neighbor])]);
            }
        }
    }
    return -1;
}
let graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'D': 2.0}, 'C': {'A': 4.0, 'D': 1.0}, 'D': {'B': 2.0, 'C': 1.0}};
console.log(find_shortest_path(graph, 'A', 'D'));