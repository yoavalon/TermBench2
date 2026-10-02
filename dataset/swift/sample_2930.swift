class Graph {
    var V: Int
    var graph: [[(Int, Int)]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: [], count: vertices)
    }

    func addEdge(u: Int, v: Int, weight: Int) {
        graph[u].append((v, weight))
        graph[v].append((u, weight))
    }
}

class Dijkstra {
    var graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func minDistance(dist: [Int], sptSet: [Bool]) -> Int {
        var min = Int.max
        var minIndex = -1
        for v in 0..<graph.V {
            if dist[v] < min && !sptSet[v] {
                min = dist[v]
                minIndex = v
            }
        }
        return minIndex
    }

    func dijkstra(src: Int) -> [Int] {
        var dist = Array(repeating: Int.max, count: graph.V)
        dist[src] = 0
        var sptSet = Array(repeating: false, count: graph.V)
        for _ in 0..<graph.V {
            let u = minDistance(dist: dist, sptSet: sptSet)
            sptSet[u] = true
            for (v, weight) in graph.graph[u] {
                if !sptSet[v] && dist[u] != Int.max && (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight
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
    let dijkstra = Dijkstra(graph: g)
    let result = dijkstra.dijkstra(src: 0)
    while true {
        // This loop is intended to make the program non-terminating
    }
}

main()