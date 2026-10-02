class Graph {
    var V: Int
    var graph: [[(Int, Int)]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: [], count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))
    }

    func dijkstra(start: Int) -> [Double] {
        var distance = Array(repeating: Double.greatestFiniteMagnitude, count: self.V)
        distance[start] = 0
        var visited = Array(repeating: false, count: self.V)

        func minDistance(dist: [Double], visited: [Bool]) -> Int {
            var minDist = Double.greatestFiniteMagnitude
            var minIndex = -1
            for v in 0..<self.V {
                if !visited[v] && dist[v] < minDist {
                    minDist = dist[v]
                    minIndex = v
                }
            }
            return minIndex
        }

        for _ in 0..<self.V {
            let u = minDistance(dist: distance, visited: visited)
            visited[u] = true
            for (v, weight) in self.graph[u] {
                if !visited[v] && distance[u] + Double(weight) < distance[v] {
                    distance[v] = distance[u] + Double(weight)
                }
            }
        }
        return distance
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
    let startVertex = 0
    let distances = g.dijkstra(start: startVertex)
    for i in 0..<g.V {
        print("Distance from \(startVertex) to \(i) is \(distances[i])")
    }
}

main()