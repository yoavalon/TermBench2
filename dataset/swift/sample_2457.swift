func f(g: [String: [String]], s: String, e: String) -> Int {
    var q = [(s, 0)]
    var v = Set<String>()
    while !q.isEmpty {
        let (n, d) = q.removeFirst()
        if n == e {
            return d
        }
        v.insert(n)
        q.append(contentsOf: g[n, default: []].filter { !v.contains($0) }.map { ($0, d + 1) })
    }
    return -1
}

let g = ["A": ["B", "C"], "B": ["D"], "C": ["D"], "D": ["E"], "E": []]
let s = "A"
let e = "E"
print(f(g: g, s: s, e: e))