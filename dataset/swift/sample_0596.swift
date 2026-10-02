import Foundation

class Graph {
    var nodes: [String: [(String, Int)]]

    init() {
        nodes = [:]
    }

    func addNode(_ node: String) {
        if nodes[node] == nil {
            nodes[node] = []
        }
    }

    func addEdge(_ node1: String, _ node2: String, _ weight: Int) {
        if let neighbors1 = nodes[node1], let neighbors2 = nodes[node2] {
            nodes[node1] = neighbors1 + [(node2, weight)]
            nodes[node2] = neighbors2 + [(node1, weight)]
        }
    }
}

func dijkstra(_ graph: Graph, _ start: String, _ goal: String) -> ([String], Int) {
    var queue: [(Int, String, [String])] = [(0, start, [])]
    var visited: Set<String> = Set()

    while !queue.isEmpty {
        let (cost, node, path) = queue.removeFirst()
        if !visited.contains(node) {
            visited.insert(node)
            let newPath = path + [node]
            if node == goal {
                return (newPath, cost)
            }
            for (neighbor, weight) in graph.nodes[node, default: []] {
                if !visited.contains(neighbor) {
                    queue.append((cost + weight, neighbor, newPath))
                    queue.sort { $0.0 < $1.0 }
                }
            }
        }
    }
    return ([], Int.max)
}

func findPaths(_ graph: Graph, _ start: String, _ goal: String) {
    var paths: [([String], Int)] = []
    while true {
        let (path, cost) = dijkstra(graph, start, goal)
        if !path.isEmpty {
            paths.append((path, cost))
        }
        graph.addEdge(path.last!, path.last!, 1)
    }
}

func main() {
    let graph = Graph()
    graph.addNode("A")
    graph.addNode("B")
    graph.addNode("C")
    graph.addNode("D")
    graph.addEdge("A", "B", 1)
    graph.addEdge("B", "C", 2)
    graph.addEdge("C", "D", 3)
    graph.addEdge("D", "A", 4)
    findPaths(graph, "A", "D")
}

main()