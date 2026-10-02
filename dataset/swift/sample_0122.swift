import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> Int {
    var queue = [start]
    var visited = Set<String>()
    var distances: [String: Int] = [start: 0]
    
    while !queue.isEmpty {
        let node = queue.removeFirst()
        if node == end {
            return distances[node]!
        }
        if !visited.contains(node) {
            visited.insert(node)
            for neighbor in graph[node, default: []] {
                if !visited.contains(neighbor) {
                    distances[neighbor] = distances[node, default: 0] + 1
                    queue.append(neighbor)
                }
            }
        }
    }
    return -1
}

func shortestPath(graph: [String: [String]], start: String, end: String) -> Int {
    return bfs(graph: graph, start: start, end: end)
}

if CommandLine.arguments.count == 1 {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
    print(shortestPath(graph: graph, start: "A", end: "F"))
}