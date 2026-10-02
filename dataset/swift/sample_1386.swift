import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String]? {
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

func findShortestPath(graph: [String: [String]], start: String, end: String) -> Int {
    if let path = bfs(graph: graph, start: start, end: end) {
        return path.count - 1
    }
    return -1
}

func main() {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
    let start = "A"
    let end = "F"
    print(findShortestPath(graph: graph, start: start, end: end))
}

main()