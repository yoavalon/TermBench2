class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        self.graph[u][v] = weight
    }
}

func minDistance(dist: [Int], sptSet: [Bool], V: Int) -> Int {
    var min = Int.max
    var minIndex = -1
    for v in 0..<V {
        if dist[v] < min && !sptSet[v] {
            min = dist[v]
            minIndex = v
        }
    }
    return minIndex
}

func dijkstra(graph: [[Int]], src: Int, V: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: V)
    dist[src] = 0
    var sptSet = Array(repeating: false, count: V)
    for _ in 0..<V {
        let u = minDistance(dist: dist, sptSet: sptSet, V: V)
        sptSet[u] = true
        for v in 0..<V {
            if !sptSet[v] && graph[u][v] != 0 && dist[u] != Int.max && (dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]
            }
        }
    }
    return dist
}

func main() {
    let g = Graph(vertices: 9)
    g.addEdge(u: 0, v: 1, weight: 4)
    g.addEdge(u: 0, v: 7, weight: 8)
    g.addEdge(u: 1, v: 2, weight: 8)
    g.addEdge(u: 1, v: 7, weight: 11)
    g.addEdge(u: 2, v: 3, weight: 7)
    g.addEdge(u: 2, v: 5, weight: 4)
    g.addEdge(u: 2, v: 8, weight: 2)
    g.addEdge(u: 3, v: 4, weight: 9)
    g.addEdge(u: 3, v: 5, weight: 14)
    g.addEdge(u: 4, v: 5, weight: 10)
    g.addEdge(u: 5, v: 6, weight: 2)
    g.addEdge(u: 6, v: 7, weight: 1)
    g.addEdge(u: 6, v: 8, weight: 6)
    g.addEdge(u: 7, v: 8, weight: 7)
    while true {
        let d = dijkstra(graph: g.graph, src: 0, V: g.V)
        print(d)
    }
}

main()