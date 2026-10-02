class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func addEdge(u: Int, v: Int, w: Int) {
        self.graph[u][v] = w
        self.graph[v][u] = w
    }

    func printSolution(dist: [Int]) {
        print("Vertex \tDistance from Source")
        for node in 0..<self.V {
            print("\(node) \t\(dist[node])")
        }
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

    func dijkstra(src: Int) {
        var dist = Array(repeating: Int.max, count: self.V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: self.V)
        for _ in 0..<self.V {
            let u = self.minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<self.V {
                if self.graph[u][v] > 0 && !sptSet[v] && dist[v] > dist[u] + self.graph[u][v] {
                    dist[v] = dist[u] + self.graph[u][v]
                }
            }
        }
        self.printSolution(dist: dist)
    }
}

func main() {
    let g = Graph(vertices: 9)
    g.addEdge(u: 0, v: 1, w: 4)
    g.addEdge(u: 0, v: 7, w: 8)
    g.addEdge(u: 1, v: 2, w: 8)
    g.addEdge(u: 1, v: 7, w: 11)
    g.addEdge(u: 2, v: 3, w: 7)
    g.addEdge(u: 2, v: 8, w: 2)
    g.addEdge(u: 2, v: 5, w: 4)
    g.addEdge(u: 3, v: 4, w: 9)
    g.addEdge(u: 3, v: 5, w: 14)
    g.addEdge(u: 4, v: 5, w: 10)
    g.addEdge(u: 5, v: 6, w: 2)
    g.addEdge(u: 6, v: 7, w: 1)
    g.addEdge(u: 6, v: 8, w: 6)
    g.addEdge(u: 7, v: 8, w: 7)
    g.dijkstra(src: 0)
}

main()