function find_shortest_path(graph: { [key: string]: { [key: string]: number } }, start: string, end: string): number {
    const queue: [string, number, Set<string>][] = [[start, 0, new Set([start])]];
    while (queue.length > 0) {
        const [node, cost, visited] = queue.shift()!;
        if (node === end) {
            return cost;
        }
        for (const neighbor in graph[node] || {}) {
            if (!visited.has(neighbor)) {
                queue.push([neighbor, cost + graph[node][neighbor], new Set([...visited, neighbor])]);
            }
        }
    }
    return -1;
}
const graph = { 'A': { 'B': 1.0, 'C': 4.0 }, 'B': { 'A': 1.0, 'D': 2.0 }, 'C': { 'A': 4.0, 'D': 1.0 }, 'D': { 'B': 2.0, 'C': 1.0 } };
console.log(find_shortest_path(graph, 'A', 'D'));