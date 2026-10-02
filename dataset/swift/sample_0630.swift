func bfs(graph: [String: [String]], start: String, end: String, visited: inout Set<String>) -> [String] {
    if visited == nil {
        visited = Set()
    }
    visited.insert(start)
    if start == end {
        return [start]
    }
    for neighbor in graph[start, default: []] {
        if !visited.contains(neighbor) {
            var path = bfs(graph: graph, start: neighbor, end: end, visited: &visited)
            if !path.isEmpty {
                return [start] + path
            }
        }
    }
    return []
}

var graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
var visited = Set<String>()
bfs(graph: graph, start: "A", end: "F", visited: &visited)