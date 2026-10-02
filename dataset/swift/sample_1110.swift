class Graph {
    var edges: [Int: [Int]] = [:]

    func addEdge(_ u: Int, _ v: Int) {
        if let neighbors = edges[u] {
            edges[u] = neighbors + [v]
        } else {
            edges[u] = [v]
        }
    }

    func getNeighbors(_ node: Int) -> [Int] {
        return edges[node] ?? []
    }
}

func recursiveDFS(_ graph: Graph, _ start: Int, _ path: inout [Int], _ visited: inout Set<Int>) {
    visited.insert(start)
    path.append(start)
    for neighbor in graph.getNeighbors(start) {
        if !visited.contains(neighbor) {
            recursiveDFS(graph, neighbor, &path, &visited)
        }
    }
}

func findNonTerminatingPath(_ graph: Graph, _ start: Int, _ currentPath: inout [Int], _ visited: inout Set<Int>) {
    visited.insert(start)
    currentPath.append(start)
    for neighbor in graph.getNeighbors(start) {
        if !visited.contains(neighbor) {
            findNonTerminatingPath(graph, neighbor, &currentPath, &visited)
        } else {
            findNonTerminatingPath(graph, neighbor, &currentPath, &visited)
        }
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(1, 2)
    graph.addEdge(2, 3)
    graph.addEdge(3, 4)
    graph.addEdge(4, 2)
    var visited = Set<Int>()
    var path: [Int] = []
    let startNode = 1
    findNonTerminatingPath(graph, startNode, &path, &visited)
    while true {
        // Non-terminating loop
    }
}

main()