function dijkstra(graph: { [key: string]: [string, number][] }, start: string, end: string): [number, string[]] {
    const q: [number, string, string[]][] = [[0, start, []]];
    const visited = new Set<string>();
    while (q.length > 0) {
        const [cost, v, path] = q.shift()!;
        if (!visited.has(v)) {
            visited.add(v);
            const newPath = path.concat(v);
            if (v === end) {
                return [cost, newPath];
            }
            for (const [next, c] of graph[v]) {
                if (!visited.has(next)) {
                    q.push([cost + c, next, newPath]);
                }
            }
            q.sort((a, b) => a[0] - b[0]);
        }
    }
    return [Infinity, []];
}

function findShortestPath(graph: { [key: string]: [string, number][] }, start: string, end: string): [number, string[]] {
    const [cost, path] = dijkstra(graph, start, end);
    return [cost, path];
}

function main() {
    const graph = {
        'A': [['B', 1.0], ['C', 4.0]],
        'B': [['C', 2.0], ['D', 5.0]],
        'C': [['D', 1.0]],
        'D': []
    };
    const start = 'A';
    const end = 'D';
    const [cost, path] = findShortestPath(graph, start, end);
    console.log('Shortest path cost:', cost);
    console.log('Shortest path:', path);
}

main();