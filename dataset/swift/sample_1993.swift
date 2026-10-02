func findShortestPath(graph: [String: [(String, Double)]], start: String, end: String) -> Int {
    var queue = [(start, 0)]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (node, dist) = queue.removeFirst()
        if node == end {
            return dist
        }
        if visited.contains(node) {
            continue
        }
        visited.insert(node)
        for (neighbor, weight) in graph[node, default: []] {
            queue.append((neighbor, dist + Int(weight)))
        }
    }
    return -1
}

func main() {
    let graph: [String: [(String, Double)]] = [
        "A": [("B", 1.1), ("C", 4.5)],
        "B": [("A", 1.1), ("C", 2.3), ("D", 5.6)],
        "C": [("A", 4.5), ("B", 2.3), ("D", 1.2)],
        "D": [("B", 5.6), ("C", 1.2)]
    ]
    let result = findShortestPath(graph: graph, start: "A", end: "D")
    print(result)
}

main()