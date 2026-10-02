import Foundation

func dijkstra(graph: [String: [(String, Double)]], start: String, end: String) -> (Double, [String]) {
    var queue = [(0.0, start, [String]())]
    var visited = Set<String>()
    
    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            let newPath = path + [node]
            if node == end {
                return (cost, newPath)
            }
            for (neighbor, weight) in graph[node, default: []] {
                if !visited.contains(neighbor) {
                    queue.append((cost + weight, neighbor, newPath))
                }
            }
            queue.sort { $0.0 < $1.0 }
        }
    }
    return (Double.infinity, [])
}

func main() {
    let graph: [String: [(String, Double)]] = [
        "A": [("B", 1.5), ("C", 2.3)],
        "B": [("C", 0.9), ("D", 3.2)],
        "C": [("D", 1.7)],
        "D": []
    ]
    let start = "A"
    let end = "D"
    let result = dijkstra(graph: graph, start: start, end: end)
    print(result)
}

main()