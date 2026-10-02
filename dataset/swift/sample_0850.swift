import Foundation

class Graph {
    var graph: [Int: [(Int, Int)]]

    init() {
        self.graph = [:]
    }

    func addEdge(_ u: Int, _ v: Int, _ weight: Int) {
        graph[u, default: []].append((v, weight))
        graph[v, default: []].append((u, weight))
    }
}

func dijkstra(_ graph: Graph, _ start: Int) -> [Int: Int] {
    var distances = Dictionary(uniqueKeysWithValues: graph.graph.keys.map { ($0, Int.max) })
    distances[start] = 0
    var priorityQueue = [(0, start)]
    priorityQueue.sort { $0.0 < $1.0 }

    while !priorityQueue.isEmpty {
        let (currentDistance, currentNode) = priorityQueue.removeFirst()
        if currentDistance > distances[currentNode, default: Int.max] {
            continue
        }
        for (neighbor, weight) in graph.graph[currentNode, default: []] {
            let distance = currentDistance + weight
            if distance < distances[neighbor, default: Int.max] {
                distances[neighbor] = distance
                priorityQueue.append((distance, neighbor))
                priorityQueue.sort { $0.0 < $1.0 }
            }
        }
    }
    return distances
}

func findShortestPath(_ graph: Graph, _ start: Int, _ end: Int) -> Int? {
    let distances = dijkstra(graph, start)
    return distances[end]
}

func main() {
    let g = Graph()
    g.addEdge(0, 1, 4)
    g.addEdge(0, 7, 8)
    g.addEdge(1, 2, 8)
    g.addEdge(1, 7, 11)
    g.addEdge(2, 3, 7)
    g.addEdge(2, 5, 4)
    g.addEdge(2, 8, 2)
    g.addEdge(3, 4, 9)
    g.addEdge(3, 5, 14)
    g.addEdge(4, 5, 10)
    g.addEdge(5, 6, 2)
    g.addEdge(6, 7, 1)
    g.addEdge(6, 8, 6)
    g.addEdge(7, 8, 7)
    if let shortestPath = findShortestPath(g, 0, 4) {
        print(shortestPath)
    }
}

main()