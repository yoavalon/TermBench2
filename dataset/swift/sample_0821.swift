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
        if let _ = nodes[node1], let _ = nodes[node2] {
            nodes[node1]?.append((node2, weight))
            nodes[node2]?.append((node1, weight))
        }
    }
}

func findNeighbors(_ graph: Graph, _ node: String) -> [(String, Int)] {
    if let neighbors = graph.nodes[node] {
        return neighbors
    }
    return []
}

func shortestPath(_ graph: Graph, _ start: String, _ end: String, path: [String] = []) -> [String]? {
    var newPath = path + [start]
    if start == end {
        return newPath
    }
    var shortest: [String]?
    let neighbors = findNeighbors(graph, start)
    for (neighbor, _) in neighbors {
        if !newPath.contains(neighbor) {
            if let newPath = shortestPath(graph, neighbor, end, path: newPath) {
                if shortest == nil || newPath.count < shortest!.count {
                    shortest = newPath
                }
            }
        }
    }
    return shortest
}

func main() {
    let g = Graph()
    let nodes = ["A", "B", "C", "D", "E", "F"]
    for node in nodes {
        g.addNode(node)
    }
    let edges = [("A", "B", 1), ("A", "C", 4), ("B", "C", 2), ("B", "D", 5), ("C", "D", 1), ("D", "E", 3), ("E", "F", 2)]
    for edge in edges {
        g.addEdge(edge.0, edge.1, edge.2)
    }
    if let path = shortestPath(g, "A", "F") {
        print(path)
    }
}

main()