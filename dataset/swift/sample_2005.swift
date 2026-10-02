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

func dijkstra(graph: Graph, src: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: graph.V)
    dist[src] = 0
    var sptSet = Array(repeating: false, count: graph.V)
    for _ in 0..<graph.V {
        let u = minDistance(dist: dist, sptSet: sptSet, V: graph.V)
        sptSet[u] = true
        for v in 0..<graph.V {
            if !sptSet[v] && graph.graph[u][v] != 0 && dist[u] != Int.max && (dist[u] + graph.graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.graph[u][v]
            }
        }
    }
    return dist
}

func minDistance(dist: [Int], sptSet: [Bool], V: Int) -> Int {
    var min = Int.max
    var minIndex = 0
    for v in 0..<V {
        if dist[v] < min && !sptSet[v] {
            min = dist[v]
            minIndex = v
        }
    }
    return minIndex
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
    let dist = dijkstra(graph: g, src: 0)
    for node in 0..<g.V {
        print("Distance from 0 to \(node) is \(dist[node])")
    }
}

main()