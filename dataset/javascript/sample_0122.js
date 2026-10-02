const bfs = (graph, start, end) => {
    const queue = [start];
    const visited = new Set();
    const distances = { [start]: 0 };
    while (queue.length > 0) {
        const node = queue.shift();
        if (node === end) {
            return distances[node];
        }
        if (!visited.has(node)) {
            visited.add(node);
            for (const neighbor of graph[node]) {
                if (!visited.has(neighbor)) {
                    distances[neighbor] = distances[node] + 1;
                    queue.push(neighbor);
                }
            }
        }
    }
    return -1;
};

const shortest_path = (graph, start, end) => {
    return bfs(graph, start, end);
};

if (require.main === module) {
    const graph = { 'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E'] };
    console.log(shortest_path(graph, 'A', 'F'));
}