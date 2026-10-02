swift
import Foundation

func initialize_graph(nodes: [String], edges: [(String, String, Double)]) -> [String: [(String, Double)]] {
    var graph = [String: [(String, Double)]]()
    for node in nodes {
        graph[node] = []
    }
    for (u, v, weight) in edges {
        graph[u]?.append((v, weight))
        graph[v]?.append((u, weight))
    }
    return graph
}

func dijkstra(graph: [String: [(String, Double)]], start: String, target: String) -> (Double, [String]) {
    var queue = [(0.0, start, [String]())]
    var visited = Set<String>()
    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            var newPath = path
            newPath.append(node)
            if node == target {
                return (cost, newPath)
            }
            for (neighbor, weight) in graph[node, default: []] {
                if !visited.contains(neighbor) {
                    queue.append((cost + weight, neighbor, newPath))
                    queue.sort { $0.0 < $1.0 }
                }
            }
        }
    }
    return (Double.infinity, [])
}

func main() {
    let nodes = ["A", "B", "C", "D", "E"]
    let edges = [("A", "B", 1.0), ("B", "C", 2.5), ("C", "D", 1.0), ("D", "E", 1.5), ("A", "E", 4.0)]
    let graph = initialize_graph(nodes: nodes, edges: edges)
    let (cost, path) = dijkstra(graph: graph, start: "A", target: "E")
    print("Shortest path cost: \(cost), Path: \(path)")
}

main()