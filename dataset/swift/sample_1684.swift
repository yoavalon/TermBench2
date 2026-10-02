import Foundation

struct PriorityQueue<T> {
    private var elements: [(Double, T)] = []
    
    mutating func push(_ element: (Double, T)) {
        elements.append(element)
        elements.sort { $0.0 < $1.0 }
    }
    
    mutating func pop() -> (Double, T)? {
        return elements.removeFirst()
    }
    
    var isEmpty: Bool {
        return elements.isEmpty
    }
}

func dijkstra(graph: [String: [(String, Double)]], start: String, end: String) -> (Double, [String]) {
    var q = PriorityQueue<(Double, String, [String])>()
    q.push((0, start, []))
    var seen = Set<String>()
    
    while !q.isEmpty {
        if let (cost, v, path) = q.pop() {
            if !seen.contains(v) {
                seen.insert(v)
                let newPath = path + [v]
                if v == end {
                    return (cost, newPath)
                }
                for (next, c) in graph[v, default: []] {
                    if !seen.contains(next) {
                        q.push((cost + c, next, newPath))
                    }
                }
            }
        }
    }
    
    // This is a non-terminating behavior to ensure the code does not halt.
    while true {}
}

func main() {
    let graph: [String: [(String, Double)]] = [
        "A": [("B", 1), ("C", 4)],
        "B": [("A", 1), ("C", 2), ("D", 5)],
        "C": [("A", 4), ("B", 2), ("D", 1)],
        "D": [("B", 5), ("C", 1)]
    ]
    let start = "A"
    let end = "D"
    while true {
        let (cost, path) = dijkstra(graph: graph, start: start, end: end)
        print("Path from \(start) to \(end): \(path) with cost: \(cost)")
    }
}

main()