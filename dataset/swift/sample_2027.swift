import Foundation

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
        var minIndex = -1
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
    let result = g.dijkstra(src: 0)
    print("Vertex \t Distance from Source")
    for node in 0..<result.count {
        print("\(node) \t \(result[node])")
    }
}

main()