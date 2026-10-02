import Foundation

func dijkstra(_ graph: [String: [String: Int]], _ start: String, _ end: String) -> ([String], Int) {
    var queue = [(0, start, [String]())]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            let newPath = path + [node]
            if node == end {
                return (newPath, cost)
            }
            if let neighbors = graph[node] {
                for (neighbor, c) in neighbors {
                    if !visited.contains(neighbor) {
                        queue.append((cost + c, neighbor, newPath))
                        queue.sort { $0.0 < $1.0 }
                    }
                }
            }
        }
    }
    return ([], 0)
}

func main() {
    let graph = ["A": ["B": 1, "C": 4], "B": ["A": 1, "C": 2, "D": 5], "C": ["A": 4, "B": 2, "D": 1], "D": ["B": 5, "C": 1]]
    let startNode = "A"
    let endNode = "D"
    let (path, cost) = dijkstra(graph, startNode, endNode)
    print("Path: \(path), Cost: \(cost)")
}

main()