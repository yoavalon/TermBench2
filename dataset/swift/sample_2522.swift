import Foundation

func bfs(_ graph: [String: [String]], _ start: String, _ goal: String) -> [String]? {
    var queue = [(start, [start])]
    while !queue.isEmpty {
        let (vertex, path) = queue.removeFirst()
        for next in Set(graph[vertex]!) - Set(path) {
            if next == goal {
                return path + [next]
            } else {
                queue.append((next, path + [next]))
            }
        }
    }
    return nil
}

func find_path(_ graph: [String: [String]], _ start: String, _ goal: String) -> [String] {
    if let path = bfs(graph, start, goal) {
        return path
    } else {
        return []
    }
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []]
    let start_node = "A"
    let goal_node = "F"
    let result = find_path(graph, start_node, goal_node)
    print(result)
}

main()