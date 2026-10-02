func findShortestPath(_ graph: [String: Set<String>], start: String, end: String) -> [String]? {
    var queue = [(start, [start])]
    while !queue.isEmpty {
        let (vertex, path) = queue.removeFirst()
        for nextVertex in graph[vertex]! - Set(path) {
            if nextVertex == end {
                return path + [nextVertex]
            } else {
                queue.append((nextVertex, path + [nextVertex]))
            }
        }
    }
    return nil
}

let graph: [String: Set<String>] = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
let start = "A"
let end = "F"
if let result = findShortestPath(graph, start: start, end: end) {
    print(result)
}