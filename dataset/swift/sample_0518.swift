import Foundation

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
}

func dijkstra(graph: Graph, src: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: graph.V)
    dist[src] = 0
    var sptSet = Array(repeating: false, count: graph.V)
    for _ in 0..<graph.V {
        let u = graph.minDistance(dist: dist, sptSet: sptSet)
        sptSet[u] = true
        for v in 0..<graph.V {
            if graph.graph[u][v] > 0 && !sptSet[v] && (dist[v] > dist[u] + graph.graph[u][v]) {
                dist[v] = dist[u] + graph.graph[u][v]
            }
        }
    }
    return dist
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
    while true {
        let src = 0
        let dist = dijkstra(graph: g, src: src)
        print("Vertex \t Distance from Source")
        for node in 0..<g.V {
            print("\(node) \t \(dist[node])")
        }
    }
}

main()