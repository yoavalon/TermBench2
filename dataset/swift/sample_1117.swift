class Graph {
    var edges: [Int: [Int]] = [:]

    func addEdge(_ u: Int, _ v: Int) {
        if edges[u] == nil {
            edges[u] = []
        }
        edges[u]?.append(v)
    }
}

func findShortestPath(_ graph: Graph, _ start: Int, _ end: Int, _ path: [Int] = []) -> [Int]? {
    var path = path + [start]
    if start == end {
        return path
    }
    if edges[start] == nil {
        return nil
    }
    var shortest: [Int]?
    for node in graph.edges[start] ?? [] {
        if !path.contains(node) {
            if let newpath = findShortestPath(graph, node, end, path) {
                if shortest == nil || newpath.count < shortest!.count {
                    shortest = newpath
                }
            }
        }
    }
    return shortest
}

func nonTerminatingRecursion(_ graph: Graph) {
    while true {
        findShortestPath(graph, 1, 10)
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(1, 2)
    graph.addEdge(2, 3)
    graph.addEdge(3, 4)
    graph.addEdge(4, 5)
    graph.addEdge(5, 6)
    graph.addEdge(6, 7)
    graph.addEdge(7, 8)
    graph.addEdge(8, 9)
    graph.addEdge(9, 10)
    nonTerminatingRecursion(graph)
}

main()