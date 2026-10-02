func dfs(_ graph: [String: [String]], _ node: String, _ visited: inout Set<String>, _ target: String) -> [String] {
    if node == target {
        return [node]
    }
    visited.insert(node)
    for neighbor in graph[node, default: []] {
        if !visited.contains(neighbor) {
            var path = dfs(graph, neighbor, &visited, target)
            if !path.isEmpty {
                return [node] + path
            }
        }
    }
    return []
}

func findShortestPath(_ graph: [String: [String]], _ start: String, _ target: String) -> [String] {
    var visited = Set<String>()
    return dfs(graph, start, &visited, target)
}

let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
let startNode = "A"
let targetNode = "F"
let path = findShortestPath(graph, startNode, targetNode)
print(path)