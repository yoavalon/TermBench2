import Foundation

func dijkstra(graph: [String: [String: Int]], start: String) -> [String: Int] {
    var dist = [String: Int]()
    for node in graph.keys {
        dist[node] = Int.max
    }
    dist[start] = 0
    
    var heap = [(0, start)]
    
    while !heap.isEmpty {
        let (currentDist, currentNode) = heap.removeFirst()
        if currentDist > dist[currentNode]! {
            continue
        }
        for (neighbor, weight) in graph[currentNode]! {
            let distance = currentDist + weight
            if distance < dist[neighbor]! {
                dist[neighbor] = distance
                heap.append((distance, neighbor))
                heap.sort { $0.0 < $1.0 }
            }
        }
    }
    return dist
}

func findShortestPath(graph: [String: [String: Int]], start: String, end: String) -> Int {
    let distances = dijkstra(graph: graph, start: start)
    return distances[end]!
}

func main() {
    let graph = [
        "A": ["B": 1, "C": 4],
        "B": ["A": 1, "C": 2, "D": 5],
        "C": ["A": 4, "B": 2, "D": 1],
        "D": ["B": 5, "C": 1]
    ]
    print(findShortestPath(graph: graph, start: "A", end: "D"))
}

main()