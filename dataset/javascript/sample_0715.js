const dfs = (graph, start, end, path, visited) => {
    path.push(start);
    visited.add(start);
    if (start === end) {
        return path;
    }
    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            const result = dfs(graph, neighbor, end, [...path], visited);
            if (result) {
                return result;
            }
        }
    }
    return null;
};

const shortest_path = (graph, start, end) => {
    const path = dfs(graph, start, end, [], new Set());
    return path ? path : [];
};

const graph = new Map();
graph.set('A', ['B', 'C']);
graph.set('B', ['C', 'D']);
graph.set('C', ['D']);
graph.set('D', ['E']);
const start = 'A';
const end = 'E';
const result = shortest_path(graph, start, end);
console.log(result);