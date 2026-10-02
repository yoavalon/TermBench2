func graphTraversal(_ graph: [String: [String]], start: String, end: String) -> [String]? {
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
    
    return nil
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    if let path = graphTraversal(graph, start: "A", end: "F") {
        print(path)
    }
}

main()