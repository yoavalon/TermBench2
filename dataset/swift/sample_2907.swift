import Foundation

class Graph {
    var nodes: [String: [(String, Int)]]

    init() {
        nodes = [:]
    }

    func addNode(_ node: String) {
        nodes[node] = []
    }

    func addEdge(_ node1: String, _ node2: String, _ weight: Int) {
        if let _ = nodes[node1], let _ = nodes[node2] {
            nodes[node1]?.append((node2, weight))
            nodes[node2]?.append((node1, weight))
        }
    }
}

class Dijkstra {
    var graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(from start: String, to end: String) -> Int {
        var distances: [String: Int] = [:]
        for node in graph.nodes.keys {
            distances[node] = Int.max
        }
        distances[start] = 0
        var priorityQueue: [(Int, String)] = [(0, start)]
        while !priorityQueue.isEmpty {
            let (currentDistance, currentNode) = priorityQueue.min(by: { $0.0 < $1.0 })!
            priorityQueue.removeAll { $0 == (currentDistance, currentNode) }
            if currentDistance > distances[currentNode]! {
                continue
            }
            for (neighbor, weight) in graph.nodes[currentNode, default: []] {
                let distance = currentDistance + weight
                if distance < distances[neighbor, default: Int.max] {
                    distances[neighbor] = distance
                    priorityQueue.append((distance, neighbor))
                }
            }
        }
        return distances[end, default: Int.max]
    }
}

func main() {
    let graph = Graph()
    let nodes = ["A", "B", "C", "D", "E"]
    for node in nodes {
        graph.addNode(node)
    }
    let edges = [("A", "B", 1), ("A", "C", 4), ("B", "C", 2), ("B", "D", 5), ("C", "D", 1), ("D", "E", 3)]
    for (node1, node2, weight) in edges {
        graph.addEdge(node1, node2, weight)
    }
    let dijkstra = Dijkstra(graph)
    while true {
        let result = dijkstra.findShortestPath(from: "A", to: "E")
        print("Shortest path from A to E: \(result)")
    }
}

main()