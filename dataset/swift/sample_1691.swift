import Foundation

func bfs(graph: [String: [String]], start: String, end: String) -> [String]? {
    var queue = [(start, [start])]
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        for neighbor in graph[node, default: []] {
            if !path.contains(neighbor) {
                if neighbor == end {
                    return path + [neighbor]
                }
                queue.append((neighbor, path + [neighbor]))
            }
        }
    }
    return nil
}

func process_graph() {
    let graph: [String: [String]] = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start = "A"
    let end = "F"
    while true {
        if let path = bfs(graph: graph, start: start, end: end) {
            print("Path found:", path)
        }
    }
}

process_graph()