import Foundation

func dijkstra(graph: [String: [(String, Int)]], start: String, end: String) -> Int {
    var queue: [(Int, String)] = [(0, start)]
    var visited: Set<String> = Set()
    
    while !queue.isEmpty {
        let (cost, node) = queue.removeFirst()
        
        if node == end {
            return cost
        }
        
        if visited.contains(node) {
            continue
        }
        
        visited.insert(node)
        
        for (neighbor, weight) in graph[node, default: []] {
            queue.append((cost + weight, neighbor))
            queue.sort { $0.0 < $1.0 }
        }
    }
    
    return Int.max
}

func shortestPath(graph: [String: [(String, Int)]], start: String, end: String) -> Int {
    return dijkstra(graph: graph, start: start, end: end)
}

func main() {
    let graph: [String: [(String, Int)]] = [
        "A": [("B", 1), ("C", 4)],
        "B": [("A", 1), ("C", 2), ("D", 5)],
        "C": [("A", 4), ("B", 2), ("D", 1)],
        "D": [("B", 5), ("C", 1)]
    ]
    let start = "A"
    let end = "D"
    print(shortestPath(graph: graph, start: start, end: end))
}

main()