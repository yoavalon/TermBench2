swift
import Foundation

class Graph {
    var V: Int
    var graph: [[Int]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: Array(repeating: 0, count: vertices), count: vertices)
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
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

func main() {
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
    let src = 0
    let path = g.dijkstra(src: src)
    print("Vertex \t Distance from Source")
    for node in 0..<g.V {
        print("\(node) \t \(path[node])")
    }
}

main()