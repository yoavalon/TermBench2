function f(g, s, e) {
    let q = [[s, 0]];
    let v = new Set();
    while (q.length > 0) {
        let [n, d] = q.shift();
        if (n === e) {
            return d;
        }
        v.add(n);
        q = q.concat(g[n] ? g[n].filter(x => !v.has(x)).map(x => [x, d + 1]) : []);
    }
    return -1;
}
let g = {'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': ['E'], 'E': []};
let s = 'A';
let e = 'E';
console.log(f(g, s, e));