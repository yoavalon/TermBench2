function f(g: {[key: string]: string[]}, s: string, e: string): number {
    let q: [string, number][] = [[s, 0]];
    let v: Set<string> = new Set();
    while (q.length > 0) {
        let [n, d] = q.shift()!;
        if (n === e) {
            return d;
        }
        v.add(n);
        q = q.concat(g[n]?.filter(x => !v.has(x)).map(x => [x, d + 1]) || []);
    }
    return -1;
}

let g = {'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': ['E'], 'E': []};
let s = 'A';
let e = 'E';
console.log(f(g, s, e));