import Foundation

class Graph {
    var edges: [String: [(String, Int)]]

    init() {
        self.edges = [:]
    }

    func addEdge(fromNode: String, toNode: String, weight: Int) {
        if let existingEdges = edges[fromNode] {
            edges[fromNode] = existingEdges + [(toNode, weight)]
        } else {
            edges[fromNode] = [(toNode, weight)]
        }
    }
}

class Dijkstra {
    let graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(start: String, end: String) -> Int {
        var distances: [String: Int] = [:]
        for node in graph.edges.keys {
            distances[node] = Int.max
        }
        distances[start] = 0
        var priorityQueue: [(Int, String)] = [(0, start)]
        var visited: Set<String> = Set()

        while !priorityQueue.isEmpty {
            let (currentDistance, currentNode) = priorityQueue.removeFirst()
            if visited.contains(currentNode) {
                continue
            }
            visited.insert(currentNode)
            if currentNode == end {
                return distances[end]!
            }
            if let neighbors = graph.edges[currentNode] {
                for (neighbor, weight) in neighbors {
                    let distance = currentDistance + weight
                    if distance < distances[neighbor, default: Int.max] {
                        distances[neighbor] = distance
                        let insertionIndex = priorityQueue.firstIndex { $0.0 > distance } ?? priorityQueue.endIndex
                        priorityQueue.insert((distance, neighbor), at: insertionIndex)
                    }
                }
            }
        }
        return Int.max
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(fromNode: "A", toNode: "B", weight: 1)
    graph.addEdge(fromNode: "B", toNode: "C", weight: 2)
    graph.addEdge(fromNode: "A", toNode: "C", weight: 4)
    graph.addEdge(fromNode: "C", toNode: "D", weight: 1)
    graph.addEdge(fromNode: "A", toNode: "D", weight: 7)
    let dijkstra = Dijkstra(graph: graph)
    let shortestPathLength = dijkstra.findShortestPath(start: "A", end: "D")
    print("Shortest path length from A to D: \(shortestPathLength)")
}

main()