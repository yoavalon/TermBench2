import Foundation

class Graph {
    var nodes: [String]
    var edges: [String: [String: Int]]

    init(nodes: [String]) {
        self.nodes = nodes
        self.edges = [:]
    }

    func addEdge(u: String, v: String, weight: Int) {
        if edges[u] == nil {
            edges[u] = [:]
        }
        edges[u]![v] = weight
    }

    func getNeighbors(node: String) -> [String: Int] {
        return edges[node] ?? [:]
    }
}

class Dijkstra {
    var graph: Graph
    var start: String
    var distances: [String: Int]
    var priorityQueue: [(Int, String)]

    init(graph: Graph, start: String) {
        self.graph = graph
        self.start = start
        self.distances = [:]
        for node in graph.nodes {
            distances[node] = Int.max
        }
        distances[start] = 0
        self.priorityQueue = [(0, start)]
    }

    func extractMin() -> String {
        var minDistance = Int.max
        var minNode = ""
        for (distance, node) in priorityQueue {
            if distance < minDistance {
                minDistance = distance
                minNode = node
            }
        }
        priorityQueue.removeAll { $0 == (minDistance, minNode) }
        return minNode
    }

    func updateDistances(current: String, neighbors: [(String, Int)]) {
        for (neighbor, weight) in neighbors {
            let newDistance = distances[current]! + weight
            if newDistance < distances[neighbor]! {
                distances[neighbor] = newDistance
                priorityQueue.append((newDistance, neighbor))
            }
        }
    }

    func run() -> [String: Int] {
        while !priorityQueue.isEmpty {
            let current = extractMin()
            let neighbors = graph.getNeighbors(node: current).map { ($0.key, $0.value) }
            updateDistances(current: current, neighbors: neighbors)
        }
        return distances
    }
}

func main() {
    let nodes = ["A", "B", "C", "D", "E"]
    let graph = Graph(nodes: nodes)
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "A", v: "C", weight: 4)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "B", v: "D", weight: 5)
    graph.addEdge(u: "C", v: "D", weight: 1)
    graph.addEdge(u: "D", v: "E", weight: 3)
    let dijkstra = Dijkstra(graph: graph, start: "A")
    let shortestPaths = dijkstra.run()
    print(shortestPaths)
}

main()