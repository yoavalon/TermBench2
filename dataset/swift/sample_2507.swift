import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String] {
    var queue: [(String, [String])] = [(start, [start])]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
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
    return []
}

func shortestPath(graph: [String: [String]], start: String, end: String) -> [String] {
    return bfs(graph: graph, start: start, end: end)
}

let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
let startNode = "A"
let endNode = "F"
let result = shortestPath(graph: graph, start: startNode, end: endNode)
print(result)