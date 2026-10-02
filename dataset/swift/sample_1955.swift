import Foundation

func dijkstra(graph: [String: [String: Double]], start: String) -> [String: Double] {
    var dist = [String: Double]()
    for node in graph.keys {
        dist[node] = .greatestFiniteMagnitude
    }
    dist[start] = 0.0
    var visited = Set<String>()
    while visited.count < graph.count {
        var minNode: String? = nil
        for node in graph.keys {
            if !visited.contains(node) && (minNode == nil || dist[node]! < dist[minNode!]!) {
                minNode = node
            }
        }
        visited.insert(minNode!)
        for (neighbor, weight) in graph[minNode!]! {
            if dist[minNode!]! + weight < dist[neighbor]! {
                dist[neighbor] = dist[minNode!]! + weight
            }
        }
    }
    return dist
}

func main() {
    let graph = [
        "A": ["B": 1.0, "C": 4.0],
        "B": ["A": 1.0, "C": 2.0, "D": 5.0],
        "C": ["A": 4.0, "B": 2.0, "D": 1.0],
        "D": ["B": 5.0, "C": 1.0]
    ]
    let startNode = "A"
    let result = dijkstra(graph: graph, start: startNode)
    print(result)
}

main()