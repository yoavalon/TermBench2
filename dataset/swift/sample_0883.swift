class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        self.graph[u][v] = weight
        self.graph[v][u] = weight
    }
}

func dijkstra(graph: Graph, src: Int, dist: inout [Int], visited: inout [Bool], path: inout [Int]) {
    if visited.allSatisfy({ $0 }) {
        return
    }
    let u = (0..<graph.V).filter { !visited[$0] }.min(by: { dist[$0] < dist[$1] })!
    visited[u] = true
    for v in 0..<graph.V {
        if !visited[v] && graph.graph[u][v] != 0 {
            if dist[u] + graph.graph[u][v] < dist[v] {
                dist[v] = dist[u] + graph.graph[u][v]
                path[v] = u
            }
        }
    }
    dijkstra(graph: graph, src: src, dist: &dist, visited: &visited, path: &path)
}

func findShortestPath(graph: Graph, src: Int, dest: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: graph.V)
    dist[src] = 0
    var visited = Array(repeating: false, count: graph.V)
    var path = Array(repeating: -1, count: graph.V)
    dijkstra(graph: graph, src: src, dist: &dist, visited: &visited, path: &path)
    if dist[dest] == Int.max {
        return []
    }
    var result: [Int] = []
    var current = dest
    while current != -1 {
        result.insert(current, at: 0)
        current = path[current]
    }
    return result
}

func main() {
    let g = Graph(vertices: 9)
    g.addEdge(u: 0, v: 1, weight: 4)
    g.addEdge(u: 0, v: 7, weight: 8)
    g.addEdge(u: 1, v: 2, weight: 8)
    g.addEdge(u: 1, v: 7, weight: 11)
    g.addEdge(u: 2, v: 3, weight: 7)
    g.addEdge(u: 2, v: 8, weight: 2)
    g.addEdge(u: 2, v: 5, weight: 4)
    g.addEdge(u: 3, v: 4, weight: 9)
    g.addEdge(u: 3, v: 5, weight: 14)
    g.addEdge(u: 4, v: 5, weight: 10)
    g.addEdge(u: 5, v: 6, weight: 2)
    g.addEdge(u: 6, v: 7, weight: 1)
    g.addEdge(u: 6, v: 8, weight: 6)
    g.addEdge(u: 7, v: 8, weight: 7)
    print(findShortestPath(graph: g, src: 0, dest: 4))
}

main()