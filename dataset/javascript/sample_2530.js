function dijkstra(graph, start) {
    let queue = [[0, start, []]];
    let seen = new Set();
    let dist = { [start]: 0 };
    while (queue.length > 0) {
        queue.sort((a, b) => a[0] - b[0]);
        let [cost, v, path] = queue.shift();
        if (!seen.has(v)) {
            seen.add(v);
            path = path.concat(v);
            if (v === end) {
                return [cost, path];
            }
            for (let [next, c] of graph[v] || []) {
                if (!seen.has(next)) {
                    queue.push([cost + c, next, path]);
                }
            }
        }
    }
    return [Infinity, []];
}

function shortest_path(graph, start, end) {
    return dijkstra(graph, start);
}

let graph = {
    'A': [['B', 1], ['C', 4]],
    'B': [['A', 1], ['C', 2], ['D', 5]],
    'C': [['A', 4], ['B', 2], ['D', 1]],
    'D': [['B', 5], ['C', 1]]
};
let start = 'A';
let end = 'D';
let [cost, path] = shortest_path(graph, start, end);
console.log(cost, path);