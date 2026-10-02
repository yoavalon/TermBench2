import Foundation

func bfs(graph: [String: Set<String>], start: String, end: String) -> [String]? {
    var queue = [(start, [start])]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        if node == end {
            return path
        }
        visited.insert(node)
        for neighbor in graph[node]!.subtracting(visited) {
            queue.append((neighbor, path + [neighbor]))
        }
    }
    return nil
}

func main() {
    let graph = [
        "A": ["B", "C"],
        "B": ["A", "D", "E"],
        "C": ["A", "F"],
        "D": ["B"],
        "E": ["B", "F"],
        "F": ["C", "E"]
    ]
    let startNode = "A"
    let endNode = "F"
    if let result = bfs(graph: graph, start: startNode, end: endNode) {
        print(result)
    } else {
        print("No path found")
    }
}

main()