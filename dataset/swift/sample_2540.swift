import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String] {
    var q = [(start, [start])]
    while !q.isEmpty {
        let (node, path) = q.removeFirst()
        if node == end {
            return path
        }
        for neighbor in graph[node, default: []] {
            if !path.contains(neighbor) {
                q.append((neighbor, path + [neighbor]))
            }
        }
    }
    return []
}

func shortest_path(graph: [String: [String]], a: String, b: String) -> [String] {
    return bfs(graph: graph, start: a, end: b)
}

func main() {
    let graph: [String: [String]] = [
        "A": ["B", "C"],
        "B": ["A", "D", "E"],
        "C": ["A", "F"],
        "D": ["B"],
        "E": ["B", "F"],
        "F": ["C", "E"]
    ]
    let start_node = "A"
    let end_node = "F"
    let path = shortest_path(graph: graph, a: start_node, b: end_node)
    print(path)
}

main()