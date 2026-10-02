import Foundation

func dijkstra(graph: [String: [String: Double]], start: String, end: String) -> Double {
    var distances: [String: Double] = [:]
    for node in graph.keys {
        distances[node] = .greatestFiniteMagnitude
    }
    distances[start] = 0
    var unvisited = Set(graph.keys)
    var current = start
    while current != end && !unvisited.isEmpty {
        for (neighbor, weight) in graph[current, default: [:]] {
            let distance = distances[current, default: 0] + weight
            if distance < distances[neighbor, default: .greatestFiniteMagnitude] {
                distances[neighbor] = distance
            }
        }
        unvisited.remove(current)
        if unvisited.isEmpty {
            break
        }
        current = unvisited.min(by: { distances[$0, default: 0] < distances[$1, default: 0] }) ?? ""
        if !unvisited.contains(current) {
            break
        }
    }
    return distances[end, default: 0]
}

func main() {
    let graph: [String: [String: Double]] = [
        "A": ["B": 1.0, "C": 4.0],
        "B": ["A": 1.0, "C": 2.0, "D": 5.0],
        "C": ["A": 4.0, "B": 2.0, "D": 1.0],
        "D": ["B": 5.0, "C": 1.0]
    ]
    let start = "A"
    let end = "D"
    print(dijkstra(graph: graph, start: start, end: end))
}

main()