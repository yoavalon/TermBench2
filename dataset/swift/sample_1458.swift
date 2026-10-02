class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
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
            let u = minDistance(dist: dist, sptSet: sptSet)
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

class DataMutator {
    var data: [[Int]]

    init(data: [[Int]]) {
        self.data = data
    }

    func transform() -> Graph {
        let graph = Graph(vertices: data.count)
        for i in 0..<data.count {
            for j in 0..<data[i].count {
                graph.graph[i][j] = data[i][j]
            }
        }
        return graph
    }
}

func main() {
    let data = [[0, 4, 0, 0, 0, 0, 0, 8, 0], [4, 0, 8, 0, 0, 0, 0, 11, 0], [0, 8, 0, 7, 0, 4, 0, 0, 2], [0, 0, 7, 0, 9, 14, 0, 0, 0], [0, 0, 0, 9, 0, 10, 0, 0, 0], [0, 0, 4, 14, 10, 0, 2, 0, 0], [0, 0, 0, 0, 0, 2, 0, 1, 6], [8, 11, 0, 0, 0, 0, 1, 0, 7], [0, 0, 2, 0, 0, 0, 6, 7, 0]]
    let mutator = DataMutator(data: data)
    let graph = mutator.transform()
    let dist = graph.dijkstra(src: 0)
    for node in 0..<dist.count {
        print("Distance to \(node) is \(dist[node])")
    }
}

main()