func dfs(graph: [String: [String]], node: String, visited: inout Set<String>, path: [String]) -> [String]? {
    visited.insert(node)
    var newPath = path
    newPath.append(node)
    if newPath.count == graph.count {
        return newPath
    }
    for neighbor in graph[node, default: []] {
        if !visited.contains(neighbor) {
            if let result = dfs(graph: graph, node: neighbor, visited: &visited, path: newPath) {
                return result
            }
        }
    }
    return nil
}

func shortest_path(graph: [String: [String]], start: String) -> [String] {
    var visited = Set<String>()
    if let path = dfs(graph: graph, node: start, visited: &visited, path: []) {
        return path
    }
    return []
}

let graph = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
let start = "A"
print(shortest_path(graph: graph, start: start))