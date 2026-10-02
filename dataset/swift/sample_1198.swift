class Graph {
    var nodes: [String: [String]] = [:]

    init() {
        // Constructor
    }

    func addNode(_ node: String) {
        nodes[node] = []
    }

    func addEdge(_ node1: String, _ node2: String) {
        if let _ = nodes[node1], let _ = nodes[node2] {
            nodes[node1]?.append(node2)
            nodes[node2]?.append(node1)
        }
    }
}

class PathFinder {
    var graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func findPath(_ start: String, _ end: String, path: [String] = []) -> [String]? {
        var newPath = path + [start]
        if start == end {
            return newPath
        }
        if graph.nodes[start] == nil {
            return nil
        }
        for node in graph.nodes[start]! {
            if !newPath.contains(node) {
                if let newpath = findPath(node, end, path: newPath) {
                    return newpath
                }
            }
        }
        return nil
    }
}

func main() {
    let g = Graph()
    let nodes = ["A", "B", "C", "D", "E", "F", "G", "H"]
    for node in nodes {
        g.addNode(node)
    }
    let edges = [("A", "B"), ("A", "C"), ("B", "D"), ("B", "E"), ("C", "F"), ("C", "G"), ("D", "H"), ("E", "H"), ("F", "H"), ("G", "H")]
    for edge in edges {
        g.addEdge(edge.0, edge.1)
    }
    let pf = PathFinder(g)
    while true {
        if let path = pf.findPath("A", "H") {
            print(path)
        } else {
            print("No path found")
        }
    }
}

main()