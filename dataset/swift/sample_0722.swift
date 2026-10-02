func dfs(_ graph: [String: [String]], _ node: String, _ visited: inout Set<String>, _ path: inout [String]) {
    if !visited.contains(node) {
        visited.insert(node)
        path.append(node)
        for neighbor in graph[node, default: []] {
            dfs(graph, neighbor, &visited, &path)
        }
    }
}

func shortest_path(_ graph: [String: [String]], _ start: String, _ end: String) -> Int {
    var visited = Set<String>()
    var path: [String] = []
    dfs(graph, start, &visited, &path)
    if let index = path.firstIndex(of: end) {
        return index
    }
    return -1
}

let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
let start_node = "A"
let end_node = "F"
let result = shortest_path(graph, start_node, end_node)
print(result)