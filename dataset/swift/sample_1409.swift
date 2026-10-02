swift
import Foundation

class Graph {
    var nodes: [String]
    var edges: [String: [(String, Int)]]

    init(nodes: [String]) {
        self.nodes = nodes
        self.edges = [:]
        for node in nodes {
            self.edges[node] = []
        }
    }

    func addEdge(node1: String, node2: String, weight: Int) {
        self.edges[node1]?.append((node2, weight))
        self.edges[node2]?.append((node1, weight))
    }
}

func dijkstra(graph: Graph, start: String, end: String) -> [String] {
    var queue: [(Int, String, [String])] = [(0, start, [])]
    var visited: Set<String> = []

    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if node == end {
            return path + [node]
        }
        if !visited.contains(node) {
            visited.insert(node)
            for (neighbor, weight) in graph.edges[node] ?? [] {
                if !visited.contains(neighbor) {
                    queue.append((cost + weight, neighbor, path + [node]))
                    queue.sort { $0.0 < $1.0 }
                }
            }
        }
    }
    return []
}

func main() {
    let nodes = ["A", "B", "C", "D", "E"]
    let graph = Graph(nodes: nodes)
    graph.addEdge(node1: "A", node2: "B", weight: 1)
    graph.addEdge(node1: "B", node2: "C", weight: 2)
    graph.addEdge(node1: "C", node2: "D", weight: 3)
    graph.addEdge(node1: "D", node2: "E", weight: 4)
    graph.addEdge(node1: "E", node2: "A", weight: 5)
    let path = dijkstra(graph: graph, start: "A", end: "E")
    print(path)
}

main()