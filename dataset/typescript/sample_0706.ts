function dfs(graph: {[key: string]: string[]}, node: string, visited: Set<string>, target: string): string[] {
    if (node === target) {
        return [node];
    }
    visited.add(node);
    for (const neighbor of graph[node]) {
        if (!visited.has(neighbor)) {
            const path = dfs(graph, neighbor, visited, target);
            if (path.length > 0) {
                return [node].concat(path);
            }
        }
    }
    return [];
}

function find_shortest_path(graph: {[key: string]: string[]}, start: string, target: string): string[] {
    const visited = new Set<string>();
    return dfs(graph, start, visited, target);
}

const graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []};
const start_node = 'A';
const target_node = 'F';
const path = find_shortest_path(graph, start_node, target_node);
console.log(path);