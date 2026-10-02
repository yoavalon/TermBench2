func findShortestPath(graph: [String: [String]], start: String, end: String, path: [String] = []) -> [String]? {
    var path = path + [start]
    if start == end {
        return path
    }
    if !graph.keys.contains(start) {
        return nil
    }
    var shortest: [String]?
    for node in graph[start, default: []] {
        if !path.contains(node) {
            if let newpath = findShortestPath(graph: graph, start: node, end: end, path: path) {
                if shortest == nil || newpath.count < shortest!.count {
                    shortest = newpath
                }
            }
        }
    }
    return shortest
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["C", "D"], "C": ["D"], "D": ["C"], "E": ["F"], "F": ["C"]]
    let start = "A"
    let end = "D"
    if let result = findShortestPath(graph: graph, start: start, end: end) {
        print(result)
    }
}

main()