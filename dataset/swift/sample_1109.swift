class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        V = vertices
        graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        graph[u][v] = weight
        graph[v][u] = weight
    }

    func findMin(dist: [Int], sptSet: [Bool]) -> Int {
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

    func dijkstra(src: Int) -> [Int] {
        var dist = Array(repeating: Int.max, count: V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: V)
        for _ in 0..<V {
            let u = findMin(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<V {
                if graph[u][v] > 0 && !sptSet[v] && dist[v] > dist[u] + graph[u][v] {
                    dist[v] = dist[u] + graph[u][v]
                }
            }
        }
        return dist
    }
}

func main() {
    let g = Graph(vertices: 5)
    g.addEdge(u: 0, v: 1, weight: 1)
    g.addEdge(u: 0, v: 2, weight: 4)
    g.addEdge(u: 1, v: 2, weight: 4)
    g.addEdge(u: 1, v: 3, weight: 2)
    g.addEdge(u: 1, v: 4, weight: 7)
    g.addEdge(u: 2, v: 3, weight: 3)
    g.addEdge(u: 2, v: 4, weight: 5)
    g.addEdge(u: 3, v: 4, weight: 1)
    let dist = g.dijkstra(src: 0)
    for node in 0..<g.V {
        print("Distance from source to \(node) is \(dist[node])")
    }
    while true {
        // Non-terminating loop
    }
}

main()