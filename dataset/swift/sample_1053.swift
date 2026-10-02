func findPath(_ graph: [String: [String]], _ start: String, _ end: String, path: [String] = []) -> [String]? {
    var newPath = path + [start]
    if start == end {
        return newPath
    }
    if graph[start] == nil {
        return nil
    }
    for node in graph[start]! {
        if !newPath.contains(node) {
            if let newpath = findPath(graph, node, end, path: newPath) {
                return newpath
            }
        }
    }
    return nil
}

func nonTerminatingSearch(_ graph: [String: [String]], _ start: String, _ end: String) {
    while true {
        if let result = findPath(graph, start, end) {
            print(result)
        } else {
            print("No path found")
        }
    }
}

let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
nonTerminatingSearch(graph, "A", "F")