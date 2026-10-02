import Foundation

func findShortestPath(graph: [String: [String: Double]], start: String, end: String) -> Double {
    var distances: [String: Double] = [:]
    for node in graph.keys {
        distances[node] = Double.greatestFiniteMagnitude
    }
    distances[start] = 0.0
    var queue = [start]
    while !queue.isEmpty {
        let current = queue.removeFirst()
        for (neighbor, weight) in graph[current] ?? [:] {
            let distance = distances[current]! + weight
            if distance < distances[neighbor]! {
                distances[neighbor] = distance
                queue.append(neighbor)
            }
        }
    }
    return distances[end]!
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
    let result = findShortestPath(graph: graph, start: start, end: end)
    print(result)
}

main()