function dijkstra(graph, start, end) {
    let q = [[0, start, []]];
    let visited = new Set();
    while (q.length > 0) {
        q.sort((a, b) => a[0] - b[0]);
        let [cost, v, path] = q.shift();
        if (!visited.has(v)) {
            visited.add(v);
            path = path.concat(v);
            if (v === end) {
                return [cost, path];
            }
            for (let [next, c] of graph[v]) {
                if (!visited.has(next)) {
                    q.push([cost + c, next, path]);
                }
            }
        }
    }
}

function find_shortest_path(graph, start, end) {
    let [cost, path] = dijkstra(graph, start, end);
    return [cost, path];
}

function main() {
    let graph = {'A': [['B', 1.0], ['C', 4.0]], 'B': [['C', 2.0], ['D', 5.0]], 'C': [['D', 1.0]], 'D': []};
    let start = 'A';
    let end = 'D';
    let [cost, path] = find_shortest_path(graph, start, end);
    console.log('Shortest path cost:', cost);
    console.log('Shortest path:', path);
}

main();