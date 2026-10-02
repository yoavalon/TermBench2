import Foundation

class Graph {
    var nodes: [String: [(String, Int)]]

    init() {
        self.nodes = [:]
    }

    func addEdge(u: String, v: String, weight: Int) {
        if let neighbors = nodes[u] {
            nodes[u] = neighbors + [(v, weight)]
        } else {
            nodes[u] = [(v, weight)]
        }
    }

    func getNeighbors(node: String) -> [(String, Int)] {
        return nodes[node] ?? []
    }
}

func dijkstra(graph: Graph, start: String, end: String) -> (Double, [String]) {
    var queue: [(Double, String, [String])] = [(0.0, start, [])]
    var visited = Set<String>()

    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            let newPath = path + [node]
            if node == end {
                return (cost, newPath)
            }
            for (neighbor, weight) in graph.getNeighbors(node: node) {
                if !visited.contains(neighbor) {
                    queue.append((cost + Double(weight), neighbor, newPath))
                    queue.sort { $0.0 < $1.0 }
                }
            }
        }
    }
    return (Double.infinity, [])
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "A", v: "C", weight: 4)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "B", v: "D", weight: 5)
    graph.addEdge(u: "C", v: "D", weight: 1)
    let (cost, path) = dijkstra(graph: graph, start: "A", end: "D")
    print("Cost: \(cost), Path: \(path)")
}

main()