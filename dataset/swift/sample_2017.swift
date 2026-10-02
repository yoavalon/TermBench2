import Foundation

class Graph {
    var edges: [String: [String: Double]] = [:]

    init() {}

    func addEdge(u: String, v: String, weight: Double) {
        if edges[u] == nil {
            edges[u] = [:]
        }
        edges[u]![v] = weight
    }
}

class Dijkstra {
    let graph: Graph
    var distances: [String: Double] = [:]
    var previous: [String: String?] = [:]

    init(graph: Graph) {
        self.graph = graph
    }

    func compute(start: String) {
        var unvisited = Set(graph.edges.keys)
        for node in unvisited {
            distances[node] = .infinity
        }
        distances[start] = 0
        while !unvisited.isEmpty {
            if let current = unvisited.min(by: { distances[$0]! < distances[$1]! }) {
                unvisited.remove(current)
                if let neighbors = graph.edges[current] {
                    for (neighbor, weight) in neighbors {
                        let distance = distances[current]! + weight
                        if distance < distances[neighbor, default: .infinity] {
                            distances[neighbor] = distance
                            previous[neighbor] = current
                        }
                    }
                }
            }
        }
    }

    func shortestPath(start: String, end: String) -> [String] {
        var path: [String] = []
        var current: String? = end
        while current != nil {
            path.append(current!)
            current = previous[current!]
        }
        return path.reversed()
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1.0)
    graph.addEdge(u: "A", v: "C", weight: 4.0)
    graph.addEdge(u: "B", v: "C", weight: 2.0)
    graph.addEdge(u: "B", v: "D", weight: 5.0)
    graph.addEdge(u: "C", v: "D", weight: 1.0)
    let dijkstra = Dijkstra(graph: graph)
    dijkstra.compute(start: "A")
    let path = dijkstra.shortestPath(start: "A", end: "D")
    print("Shortest path:", path)
}

main()