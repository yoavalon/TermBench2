func dfs(graph: [String: [String]], start: String, end: String, path: [String], visited: Set<String>) -> [String]? {
    var newPath = path + [start]
    var newVisited = visited
    newVisited.insert(start)
    if start == end {
        return newPath
    }
    for neighbor in graph[start, default: []] {
        if !newVisited.contains(neighbor) {
            if let result = dfs(graph: graph, start: neighbor, end: end, path: newPath, visited: newVisited) {
                return result
            }
        }
    }
    return nil
}

func findShortestPath(graph: [String: [String]], start: String, end: String) -> [String]? {
    return dfs(graph: graph, start: start, end: end, path: [], visited: [])
}

let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
if let path = findShortestPath(graph: graph, start: "A", end: "F") {
    print("Path found:", path)
} else {
    print("No path found")
}