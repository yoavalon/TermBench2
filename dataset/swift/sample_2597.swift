func findShortestPath(_ graph: [String: [String]], _ start: String, _ end: String) -> [String] {
    var queue = [(start, [start])]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        if node == end {
            return path
        }
        if !visited.contains(node) {
            visited.insert(node)
            for neighbor in graph[node, default: []] {
                queue.append((neighbor, path + [neighbor]))
            }
        }
    }
    return []
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
    let path = findShortestPath(graph, "A", "F")
    print(path)
}

main()