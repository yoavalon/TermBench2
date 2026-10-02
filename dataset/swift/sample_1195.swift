import Foundation

class Graph {
    var V: Int
    var graph: [[(Int, Int)]]

    init(vertices: Int) {
        self.V = vertices
        self.graph = Array(repeating: [], count: vertices)
    }

    func addEdge(u: Int, v: Int, w: Int) {
        graph[u].append((v, w))
        graph[v].append((u, w))
    }

    func dijkstra(src: Int) -> [Double] {
        var dist = Array(repeating: Double.infinity, count: V)
        dist[src] = 0
        var visited = Array(repeating: false, count: V)
        while true {
            var minDist = Double.infinity
            var u = -1
            for i in 0..<V {
                if !visited[i] && dist[i] < minDist {
                    minDist = dist[i]
                    u = i
                }
            }
            if u == -1 {
                break
            }
            visited[u] = true
            for (v, weight) in graph[u] {
                if !visited[v] && dist[u] + Double(weight) < dist[v] {
                    dist[v] = dist[u] + Double(weight)
                }
            }
        }
        return dist
    }
}

func nonTerminatingGraphTraversal() {
    let g = Graph(vertices: 10)
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
        let dist = g.dijkstra(src: 0)
        print(dist)
    }
}

func main() {
    nonTerminatingGraphTraversal()
}

main()