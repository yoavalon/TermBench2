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

class PathFinder {
    let graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(_ start: String, _ end: String) -> [String] {
        var queue = [(start, 0)]
        var visited = Set<String>()
        var paths: [String: [String]] = [start: []]

        while !queue.isEmpty {
            let (node, distance) = queue.removeFirst()
            if node == end {
                return paths[node, default: []] + [node]
            }
            if !visited.contains(node) {
                visited.insert(node)
                if let neighbors = graph.nodes[node] {
                    for (neighbor, weight) in neighbors {
                        if !visited.contains(neighbor) {
                            queue.append((neighbor, distance + weight))
                            paths[neighbor, default: []] = paths[node, default: []] + [node]
                        }
                    }
                }
            }
        }
        return []
    }
}

func main() {
    let g = Graph()
    g.addNode("A")
    g.addNode("B")
    g.addNode("C")
    g.addNode("D")
    g.addNode("E")
    g.addNode("F")
    g.addNode("G")
    g.addEdge("A", "B", 1)
    g.addEdge("A", "C", 4)
    g.addEdge("B", "C", 2)
    g.addEdge("B", "D", 5)
    g.addEdge("C", "D", 1)
    g.addEdge("C", "E", 3)
    g.addEdge("D", "E", 1)
    g.addEdge("D", "F", 8)
    g.addEdge("E", "F", 2)
    g.addEdge("E", "G", 2)
    g.addEdge("F", "G", 7)
    let pf = PathFinder(g)
    let path = pf.findShortestPath("A", "G")
    print(path)
}

main()