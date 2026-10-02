import Foundation

func bfs(_ graph: [String: [String]], start: String, end: String) -> [String] {
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

func shortestPath(_ graph: [String: [String]], start: String, end: String) -> [String] {
    return bfs(graph, start: start, end: end)
}

let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
let start = "A"
let end = "F"
print(shortestPath(graph, start: start, end: end))