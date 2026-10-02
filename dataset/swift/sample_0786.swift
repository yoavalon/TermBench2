func findPath(graph: [String: [String]], start: String, end: String, path: [String] = []) -> [String]? {
    var path = path + [start]
    if start == end {
        return path
    }
    if graph[start] == nil {
        return nil
    }
    for node in graph[start]! {
        if !path.contains(node) {
            if let newpath = findPath(graph: graph, start: node, end: end, path: path) {
                return newpath
            }
        }
    }
    return nil
}

func shortestPath(graph: [String: [String]], start: String, end: String) -> Int {
    if let path = findPath(graph: graph, start: start, end: end) {
        return path.count - 1
    }
    return Int.max
}

let g = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
print(shortestPath(graph: g, start: "A", end: "F"))