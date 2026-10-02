import Foundation

func initializeGraph(nodes: [String], edges: [(String, String, Int)]) -> [String: [(String, Int)]] {
    var graph: [String: [(String, Int)]] = [:]
    for node in nodes {
        graph[node] = []
    }
    for (u, v, weight) in edges {
        graph[u]?.append((v, weight))
        graph[v]?.append((u, weight))
    }
    return graph
}

func findShortestPath(graph: [String: [(String, Int)]], start: String, end: String) -> (Int, [String]) {
    var queue: [(Int, String, [String])] = [(0, start, [])]
    var visited: Set<String> = []
    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if visited.contains(node) {
            continue
        }
        let newPath = path + [node]
        visited.insert(node)
        if node == end {
            return (cost, newPath)
        }
        for (neighbor, weight) in graph[node] ?? [] {
            if !visited.contains(neighbor) {
                queue.append((cost + weight, neighbor, newPath))
                queue.sort { $0.0 < $1.0 }
            }
        }
    }
    return (Int.max, [])
}

func main() {
    let nodes = ["A", "B", "C", "D", "E"]
    let edges = [("A", "B", 1), ("B", "C", 2), ("C", "D", 3), ("D", "E", 4), ("E", "A", 5)]
    let graph = initializeGraph(nodes: nodes, edges: edges)
    let start = "A"
    let end = "E"
    let (cost, path) = findShortestPath(graph: graph, start: start, end: end)
    print("Cost: \(cost), Path: \(path)")
}

main()