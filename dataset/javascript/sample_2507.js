function bfs(graph, start, end) {
    const queue = [[start, [start]]];
    const visited = new Set();
    while (queue.length > 0) {
        const [node, path] = queue.shift();
        visited.add(node);
        if (node === end) {
            return path;
        }
        for (const neighbor of graph[node]) {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, path.concat(neighbor)]);
            }
        }
    }
    return [];
}

function shortest_path(graph, start, end) {
    return bfs(graph, start, end);
}

const graph = { 'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': [] };
const start_node = 'A';
const end_node = 'F';
const result = shortest_path(graph, start_node, end_node);
console.log(result);