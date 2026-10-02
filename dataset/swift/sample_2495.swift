import Foundation

func findShortestPath(graph: [String: [String]], start: String, end: String) -> Int {
    var q = [(start, 0)]
    var v = Set<String>()
    
    while !q.isEmpty {
        let (n, d) = q.removeFirst()
        if n == end {
            return d
        }
        v.insert(n)
        for nxt in graph[n, default: []].filter({ !v.contains($0) }) {
            q.append((nxt, d + 1))
        }
    }
    return -1
}

let g = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": ["G"], "E": ["F"], "F": ["G"], "G": []]
let result = findShortestPath(graph: g, start: "A", end: "G")
print(result)