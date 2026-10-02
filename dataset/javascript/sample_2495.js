function find_shortest_path(graph, start, end) {
    let q = [[start, 0]];
    let v = new Set();
    while (q.length > 0) {
        let [n, d] = q.shift();
        if (n === end) {
            return d;
        }
        v.add(n);
        q = q.concat(graph[n] ? graph[n].filter(nxt => !v.has(nxt)).map(nxt => [nxt, d + 1]) : []);
    }
    return -1;
}
let g = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F'], 'F': ['G'], 'G': []};
let result = find_shortest_path(g, 'A', 'G');
console.log(result);