import Foundation

func bfsShortestPath(graph: [String: [String]], start: String, goal: String) -> [String]? {
    var queue: [(String, [String])] = [(start, [start])]
    var visited = Set<String>()
    
    while !queue.isEmpty {
        let (node, path) = queue.removeFirst()
        if node == goal {
            return path
        }
        if !visited.contains(node) {
            visited.insert(node)
            for neighbor in graph[node, default: []] {
                if !visited.contains(neighbor) {
                    queue.append((neighbor, path + [neighbor]))
                }
            }
        }
    }
    return nil
}

func main() {
    let graph = ["A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": ["G"], "E": ["F"], "F": ["G"], "G": []]
    let startNode = "A"
    let goalNode = "G"
    if let result = bfsShortestPath(graph: graph, start: startNode, goal: goalNode) {
        print(result)
    }
}

main()