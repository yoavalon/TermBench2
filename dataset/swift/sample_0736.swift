func dfs(_ graph: [String: [String]], _ node: String, _ visited: inout Set<String>, _ path: inout [String]) -> [String] {
    if !visited.contains(node) {
        visited.insert(node)
        path.append(node)
        for neighbor in graph[node, default: []] {
            dfs(graph, neighbor, &visited, &path)
        }
    }
    return path
}

func shortestPath(_ graph: [String: [String]], _ start: String, _ end: String) -> [String] {
    var visited = Set<String>()
    var path = dfs(graph, start, &visited, [])
    return path.contains(end) ? path : []
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    let result = shortestPath(graph, start, end)
    print(result)
}

main()