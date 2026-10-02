class Graph {
    var edges: [String: [String: Int]] = [:]

    init() {}

    func addEdge(node1: String, node2: String, weight: Int) {
        if edges[node1] == nil {
            edges[node1] = [:]
        }
        if edges[node2] == nil {
            edges[node2] = [:]
        }
        edges[node1]![node2] = weight
        edges[node2]![node1] = weight
    }

    func getNeighbors(node: String) -> [String: Int] {
        return edges[node] ?? [:]
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
        var unvisited = Array(graph.edges.keys)

        while !unvisited.isEmpty {
            let current = unvisited.min { distances[$0]! < distances[$1]! }!
            unvisited.removeAll { $0 == current }
            if current == end {
                break
            }
            for (neighbor, weight) in graph.getNeighbors(node: current) {
                let distance = distances[current]! + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                }
            }
        }
        return distances[end]!
    }
}

func main() {
    let g = Graph()
    g.addEdge(node1: "A", node2: "B", weight: 1)
    g.addEdge(node1: "B", node2: "C", weight: 2)
    g.addEdge(node1: "C", node2: "D", weight: 3)
    g.addEdge(node1: "A", node2: "D", weight: 10)
    g.addEdge(node1: "B", node2: "D", weight: 4)
    let dijkstra = Dijkstra(graph: g)
    let result = dijkstra.findShortestPath(start: "A", end: "D")
    print(result)
}

main()