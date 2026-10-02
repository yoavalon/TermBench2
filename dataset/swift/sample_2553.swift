import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String]? {
    var queue = [(start, [start])]
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        for neighbor in graph[node, default: []] {
            if neighbor == end {
                return path + [neighbor]
            } else if !path.contains(neighbor) {
                queue.append((neighbor, path + [neighbor]))
            }
        }
    }
    return nil
}

func findShortestPath(graph: [String: [String]], start: String, end: String) -> [String]? {
    return bfs(graph: graph, start: start, end: end)
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    if let path = findShortestPath(graph: graph, start: start, end: end) {
        print(path.joined(separator: " -> "))
    } else {
        print("No path found")
    }
}

main()