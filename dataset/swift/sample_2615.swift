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

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
        var min = Int.max
        var minIndex = 0
        for v in 0..<self.V {
            if dist[v] < min && !sptSet[v] {
                min = dist[v]
                minIndex = v
            }
        }
        return minIndex
    }

    func dijkstra(src: Int) -> [Int] {
        var dist = Array(repeating: Int.max, count: self.V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: self.V)
        for _ in 0..<self.V {
            let u = minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<self.V {
                if self.graph[u][v] > 0 && !sptSet[v] && (dist[v] > dist[u] + self.graph[u][v]) {
                    dist[v] = dist[u] + self.graph[u][v]
                }
            }
        }
        return dist
    }
}

func generateSequence(n: Int) -> Graph {
    let g = Graph(vertices: n)
    for i in 0..<n {
        for j in (i + 1)..<n {
            let weight = abs(i - j)
            g.addEdge(u: i, v: j, weight: weight)
        }
    }
    return g
}

func findShortestPath(graph: Graph, src: Int, dest: Int) -> Int {
    let pathLengths = graph.dijkstra(src: src)
    return pathLengths[dest]
}

func main() {
    let n = 10
    let graph = generateSequence(n: n)
    let src = 0
    let dest = n - 1
    let result = findShortestPath(graph: graph, src: src, dest: dest)
    print("Shortest path from \(src) to \(dest): \(result)")
}

main()