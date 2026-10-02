import Foundation

func dijkstra(graph: [String: [String: Double]], start: String) -> [String: Double] {
    var dist = [String: Double]()
    for node in graph.keys {
        dist[node] = Double.greatestFiniteMagnitude
    }
    dist[start] = 0.0
    var priorityQueue = [(Double, String)]()
    priorityQueue.append((0.0, start))
    
    while !priorityQueue.isEmpty {
        let (currentDist, currentNode) = priorityQueue.removeFirst()
        if currentDist > dist[currentNode]! {
            continue
        }
        for (neighbor, weight) in graph[currentNode]! {
            let distance = currentDist + weight
            if distance < dist[neighbor]! {
                dist[neighbor] = distance
                priorityQueue.append((distance, neighbor))
                priorityQueue.sort { $0.0 < $1.0 }
            }
        }
    }
    return dist
}

func main() {
    let graph = [
        "A": ["B": 1.1, "C": 4.2],
        "B": ["A": 1.1, "C": 2.3, "D": 5.5],
        "C": ["A": 4.2, "B": 2.3, "D": 1.0],
        "D": ["B": 5.5, "C": 1.0]
    ]
    let startNode = "A"
    let result = dijkstra(graph: graph, start: startNode)
    print(result)
}

main()