func dfs(_ graph: [String: [String]], _ node: String, _ visited: inout Set<String>, _ path: inout [String]) -> [String] {
    visited.insert(node)
    path.append(node)
    for neighbor in graph[node, default: []] {
        if !visited.contains(neighbor) {
            dfs(graph, neighbor, &visited, &path)
        }
    }
    return path
}

func shortestPath(_ graph: [String: [String]], _ start: String, _ end: String) -> [String]? {
    var visited = Set<String>()
    var path = [String]()
    path = dfs(graph, start, &visited, &path)
    return path.contains(end) ? path : nil
}

let graph: [String: [String]] = ["A": ["B", "C"], "B": ["A", "D", "E"], "C": ["A", "F"], "D": ["B"], "E": ["B", "F"], "F": ["C", "E"]]
let startNode = "A"
let endNode = "F"
if let result = shortestPath(graph, startNode, endNode) {
    print(result)
}