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

func dijkstra(graph: Graph, src: Int) -> [Int] {
    var dist = Array(repeating: Int.max, count: graph.V)
    dist[src] = 0
    var visited = Array(repeating: false, count: graph.V)

    func minDistance(dist: [Int], visited: [Bool]) -> Int {
        var minVal = Int.max
        var minIndex = -1
        for v in 0..<graph.V {
            if dist[v] < minVal && !visited[v] {
                minVal = dist[v]
                minIndex = v
            }
        }
        return minIndex
    }

    for _ in 0..<graph.V {
        let u = minDistance(dist: dist, visited: visited)
        visited[u] = true
        for (v, weight) in graph.graph[u] {
            if !visited[v] && dist[u] + weight < dist[v] {
                dist[v] = dist[u] + weight
            }
        }
    }
    return dist
}

func nonTerminatingDijkstra(graph: Graph, start: Int) {
    while true {
        let result = dijkstra(graph: graph, src: start)
        print(result)
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
    nonTerminatingDijkstra(graph: g, start: 0)
}

main()