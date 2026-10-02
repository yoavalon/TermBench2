class Graph {
    var edges: [Int: [(Int, Int)]]

    init() {
        self.edges = [:]
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        if let existingEdges = edges[u] {
            edges[u] = existingEdges + [(v, weight)]
        } else {
            edges[u] = [(v, weight)]
        }
    }

    func getNeighbors(node: Int) -> [(Int, Int)] {
        return edges[node] ?? []
    }
}

func findPath(graph: Graph, start: Int, end: Int, path: [Int] = []) -> [Int]? {
    let newPath = path + [start]
    if start == end {
        return newPath
    }
    if graph.edges[start] == nil {
        return nil
    }
    for (node, weight) in graph.getNeighbors(node: start) {
        if !newPath.contains(node) {
            if let newpath = findPath(graph: graph, start: node, end: end, path: newPath) {
                return newpath
            }
        }
    }
    return nil
}

func shortestPath(graph: Graph, start: Int, end: Int, path: [Int] = [], minWeight: Int = Int.max) -> ([Int]?, Int) {
    let newPath = path + [start]
    if start == end {
        return (newPath, 0)
    }
    if graph.edges[start] == nil {
        return (nil, Int.max)
    }
    var minPath: [Int]?
    for (node, weight) in graph.getNeighbors(node: start) {
        if !newPath.contains(node) {
            let (newpath, newWeight) = shortestPath(graph: graph, start: node, end: end, path: newPath, minWeight: minWeight)
            if let newpath = newpath {
                let totalWeight = weight + newWeight
                if totalWeight < minWeight {
                    minWeight = totalWeight
                    minPath = [start] + newpath
                }
            }
        }
    }
    return (minPath, minWeight)
}

func main() {
    let g = Graph()
    g.addEdge(u: 1, v: 2, weight: 7)
    g.addEdge(u: 1, v: 3, weight: 9)
    g.addEdge(u: 2, v: 3, weight: 10)
    g.addEdge(u: 2, v: 4, weight: 15)
    g.addEdge(u: 3, v: 4, weight: 11)
    g.addEdge(u: 3, v: 6, weight: 2)
    g.addEdge(u: 4, v: 5, weight: 6)
    g.addEdge(u: 5, v: 6, weight: 9)
    while true {
        if let path = findPath(graph: g, start: 1, end: 6) {
            print("Path found:", path)
        }
        let (minPath, minWeight) = shortestPath(graph: g, start: 1, end: 6)
        if let minPath = minPath {
            print("Shortest path:", minPath, "with weight", minWeight)
        }
    }
}

main()