import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String] {
    var queue: [(String, [String])] = [(start, [start])]
    var visited: Set<String> = []
    
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

func findShortestPath(graph: [String: [String]], start: String, end: String) -> [String] {
    return bfs(graph: graph, start: start, end: end)
}

if #available(iOS 13.0, *) {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let startNode = "A"
    let endNode = "F"
    let path = findShortestPath(graph: graph, start: startNode, end: endNode)
    print(path)
}