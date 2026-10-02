function initializeGraph(nodes: string[], edges: [string, string, number][]): { [key: string]: [string, number][] } {
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

function findShortestPath(graph: { [key: string]: [string, number][] }, start: string, end: string): [number, string[]] {
    const queue: [number, string, string[]][] = [[0, start, []]];
    const visited: Set<string> = new Set();
    while (queue.length > 0) {
        queue.sort((a, b) => a[0] - b[0]);
        const [cost, node, path] = queue.shift()!;
        if (visited.has(node)) {
            continue;
        }
        const newPath = path.concat([node]);
        visited.add(node);
        if (node === end) {
            return [cost, newPath];
        }
        for (const [neighbor, weight] of graph[node]) {
            if (!visited.has(neighbor)) {
                queue.push([cost + weight, neighbor, newPath]);
            }
        }
    }
    return [Infinity, []];
}

function main() {
    const nodes = ['A', 'B', 'C', 'D', 'E'];
    const edges = [['A', 'B', 1], ['B', 'C', 2], ['C', 'D', 3], ['D', 'E', 4], ['E', 'A', 5]];
    const graph = initializeGraph(nodes, edges);
    const start = 'A';
    const end = 'E';
    const [cost, path] = findShortestPath(graph, start, end);
    console.log(`Cost: ${cost}, Path: ${path}`);
}

main();