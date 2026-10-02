func bfs(_ graph: [String: [String]], _ start: String, _ end: String) -> [String]? {
    var queue = [(start, [start])]
    var visited = Set<String>()
    
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            if node == end {
                return path
            }
            for neighbor in graph[node, default: []] {
                if !visited.contains(neighbor) {
                    queue.append((neighbor, path + [neighbor]))
                }
            }
        }
    }
    return nil
}

func findShortestPath(_ graph: [String: [String]], _ start: String, _ end: String) -> Int {
    if let path = bfs(graph, start, end) {
        return path.count - 1
    }
    return -1
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    let result = findShortestPath(graph, start, end)
    print(result)
}

main()