class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
        var minDist = Int.max
        var minIndex = -1
        for v in 0..<self.V {
            if dist[v] < minDist && !sptSet[v] {
                minDist = dist[v]
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
            let u = self.minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<self.V {
                if self.graph[u][v] > 0 && !sptSet[v] && dist[v] > dist[u] + self.graph[u][v] {
                    dist[v] = dist[u] + self.graph[u][v]
                }
            }
        }
        return dist
    }
}

func constructGraph() -> Graph {
    let g = Graph(vertices: 9)
    g.graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    return g
}

func main() {
    let graph = constructGraph()
    let distances = graph.dijkstra(src: 0)
    print(distances)
}

main()