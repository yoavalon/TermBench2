import Foundation

func dijkstra(graph: [String: [String: Double]], start: String) -> [String: Double] {
    var distances: [String: Double] = [:]
    for node in graph.keys {
        distances[node] = Double.infinity
    }
    distances[start] = 0.0
    var priorityQueue: [(Double, String)] = [(0.0, start)]
    
    while !priorityQueue.isEmpty {
        let (currentDistance, currentNode) = priorityQueue.removeFirst()
        if currentDistance > distances[currentNode]! {
            continue
        }
        for (neighbor, weight) in graph[currentNode]! {
            let distance = currentDistance + weight
            if distance < distances[neighbor]! {
                distances[neighbor] = distance
                priorityQueue.append((distance, neighbor))
                priorityQueue.sort { $0.0 < $1.0 }
            }
        }
    }
    return distances
}

func main() {
    let graph: [String: [String: Double]] = [
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