import Foundation

func dijkstra(graph: [String: [String: Int]], start: String, end: String) -> Int {
    var dist = [String: Int]()
    for node in graph.keys {
        dist[node] = Int.max
    }
    dist[start] = 0
    var queue = [(0, start)]
    
    while !queue.isEmpty {
        let (currentDist, currentNode) = queue.removeFirst()
        if currentDist > dist[currentNode]! {
            continue
        }
        for (neighbor, weight) in graph[currentNode]! {
            let distance = currentDist + weight
            if distance < dist[neighbor]! {
                dist[neighbor] = distance
                queue.append((distance, neighbor))
                queue.sort { $0.0 < $1.0 }
            }
        }
    }
    return dist[end]!
}

func main() {
    let graph = [
        "A": ["B": 1, "C": 4],
        "B": ["A": 1, "C": 2, "D": 5],
        "C": ["A": 4, "B": 2, "D": 1],
        "D": ["B": 5, "C": 1]
    ]
    let start = "A"
    let end = "D"
    let result = dijkstra(graph: graph, start: start, end: end)
    print(result)
}

main()