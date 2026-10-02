function initialize_graph(nodes: string[], edges: [string, string, number][]): { [key: string]: [string, number][] } {
    const graph: { [key: string]: [string, number][] } = {};
    for (const node of nodes) {
        graph[node] = [];
    }
    for (const [u, v, weight] of edges) {
        graph[u].push([v, weight]);
        graph[v].push([u, weight]);
    }
    return graph;
}

function dijkstra(graph: { [key: string]: [string, number][] }, start: string, target: string): [number, string[]] {
    const queue: [number, string, string[]][] = [[0, start, []]];
    const visited = new Set<string>();
    while (queue.length > 0) {
        const [cost, node, path] = queue.shift()!;
        if (!visited.has(node)) {
            visited.add(node);
            const newPath = path.concat([node]);
            if (node === target) {
                return [cost, newPath];
            }
            for (const [neighbor, weight] of graph[node]) {
                if (!visited.has(neighbor)) {
                    queue.push([cost + weight, neighbor, newPath]);
                    queue.sort((a, b) => a[0] - b[0]);
                }
            }
        }
    }
    return [Infinity, []];
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const edges: [string, string, number][] = [['A', 'B', 1.0], ['B', 'C', 2.5], ['C', 'D', 1.0], ['D', 'E', 1.5], ['A', 'E', 4.0]];
    const graph = initialize_graph(nodes, edges);
    const [cost, path] = dijkstra(graph, 'A', 'E');
    console.log(`Shortest path cost: ${cost}, Path: ${path}`);
}

main();