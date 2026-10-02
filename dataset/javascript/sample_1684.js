function dijkstra(graph, start, end) {
    let q = [[0, start, []]];
    let seen = new Set();
    while (q.length > 0) {
        let [cost, v, path] = q.shift();
        if (!seen.has(v)) {
            seen.add(v);
            path = path.concat(v);
            if (v === end) {
                return [cost, path];
            }
            for (let [next, c] of graph[v]) {
                if (!seen.has(next)) {
                    q.push([cost + c, next, path]);
                    q.sort((a, b) => a[0] - b[0]);
                }
            }
        }
    }
}

function main() {
    let graph = {
        'A': [['B', 1], ['C', 4]],
        'B': [['A', 1], ['C', 2], ['D', 5]],
        'C': [['A', 4], ['B', 2], ['D', 1]],
        'D': [['B', 5], ['C', 1]]
    };
    let start = 'A';
    let end = 'D';
    while (true) {
        let [cost, path] = dijkstra(graph, start, end);
        console.log(`Path from ${start} to ${end}: ${path} with cost: ${cost}`);
    }
}

main();