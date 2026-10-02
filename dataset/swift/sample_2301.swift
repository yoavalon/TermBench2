import Foundation

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
}

class ShortestPath {
    var graph: Graph
    var V: Int

    init(graph: Graph) {
        self.graph = graph
        self.V = graph.V
    }

    func dijkstra(src: Int) -> [Double] {
        var dist = Array(repeating: Double.greatestFiniteMagnitude, count: V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: V)
        for _ in 0..<V {
            let u = minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for v in 0..<V {
                if !sptSet[v] && graph.graph[u][v] != 0 && dist[u] != Double.greatestFiniteMagnitude && (dist[u] + Double(graph.graph[u][v]) < dist[v]) {
                    dist[v] = dist[u] + Double(graph.graph[u][v])
                }
            }
        }
        return dist
    }

    func minDistance(dist: [Double], sptSet: [Bool]) -> Int {
        var min = Double.greatestFiniteMagnitude
        var minIndex = -1
        for v in 0..<V {
            if dist[v] < min && !sptSet[v] {
                min = dist[v]
                minIndex = v
            }
        }
        return minIndex
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
    let shortestPathFinder = ShortestPath(graph: g)
    var distances = shortestPathFinder.dijkstra(src: 0)
    while true {
        print(distances)
        for i in 0..<distances.count {
            distances[i] += 0.0001
        }
    }
}

main()