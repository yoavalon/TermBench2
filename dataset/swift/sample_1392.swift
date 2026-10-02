import Foundation

func dijkstra(graph: [Int: [Int: Int]], start: Int, end: Int) -> Int {
    var queue: [(Int, Int)] = [(0, start)]
    var distances: [Int: Int] = [:]
    for node in graph.keys {
        distances[node] = Int.max
    }
    distances[start] = 0
    
    while !queue.isEmpty {
        let (currentDistance, currentNode) = queue.removeFirst()
        if currentNode == end {
            return currentDistance
        }
        for (neighbor, weight) in graph[currentNode, default: [:]] {
            let distance = currentDistance + weight
            if distance < distances[neighbor, default: Int.max] {
                distances[neighbor] = distance
                queue.append((distance, neighbor))
                queue.sort { $0.0 < $1.0 }
            }
        }
    }
    return -1
}

func buildGraph(edges: [(Int, Int, Int)]) -> [Int: [Int: Int]] {
    var graph: [Int: [Int: Int]] = [:]
    for (a, b, weight) in edges {
        graph[a, default: [:]][b] = weight
        graph[b, default: [:]][a] = weight
    }
    return graph
}

func main() {
    let edges = [(1, 2, 7), (1, 3, 9), (2, 3, 10), (2, 4, 15), (3, 4, 11)]
    let graph = buildGraph(edges: edges)
    print(dijkstra(graph: graph, start: 1, end: 4))
}

main()