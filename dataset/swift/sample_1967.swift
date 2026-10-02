import Foundation

func dijkstra(graph: [String: [(String, Double)]], start: String, end: String) -> (Double, [String]) {
    var q = [(0.0, start, [String]())]
    var visited = Set<String>()
    
    while !q.isEmpty {
        let (cost, v, path) = q.removeFirst()
        
        if !visited.contains(v) {
            visited.insert(v)
            let newPath = path + [v]
            
            if v == end {
                return (cost, newPath)
            }
            
            for (next, c) in graph[v, default: []] {
                if !visited.contains(next) {
                    q.append((cost + c, next, newPath))
                    q.sort { $0.0 < $1.0 }
                }
            }
        }
    }
    
    return (0.0, [])
}

func findShortestPath(graph: [String: [(String, Double)]], start: String, end: String) -> (Double, [String]) {
    return dijkstra(graph: graph, start: start, end: end)
}

func main() {
    let graph: [String: [(String, Double)]] = [
        "A": [("B", 1.0), ("C", 4.0)],
        "B": [("C", 2.0), ("D", 5.0)],
        "C": [("D", 1.0)],
        "D": []
    ]
    let start = "A"
    let end = "D"
    let (cost, path) = findShortestPath(graph: graph, start: start, end: end)
    print("Shortest path cost:", cost)
    print("Shortest path:", path)
}

main()