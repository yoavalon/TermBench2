swift
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

func shortestPath(graph: [String: [String]], start: String, end: String) -> [String]? {
    return bfs(graph: graph, start: start, end: end)
}

func main() {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    if let path = shortestPath(graph: graph, start: start, end: end) {
        print("Shortest path:", path)
    } else {
        print("No path found")
    }
}

main()