import Foundation

class Graph {
    var V: Int
    var graph: [[(Int, Int)]]

    init(vertices: Int) {
        V = vertices
        graph = Array(repeating: [], count: vertices)
    }

    func addEdge(u: Int, v: Int, w: Int) {
        graph[u].append((v, w))
    }

    func bellmanFord(src: Int) -> [Int]? {
        var dist = Array(repeating: Int.max, count: V)
        dist[src] = 0
        for _ in 0..<(V - 1) {
            for u in 0..<V {
                for (v, w) in graph[u] {
                    if dist[u] != Int.max && dist[u] + w < dist[v] {
                        dist[v] = dist[u] + w
                    }
                }
            }
        }
        for u in 0..<V {
            for (v, w) in graph[u] {
                if dist[u] != Int.max && dist[u] + w < dist[v] {
                    return nil
                }
            }
        }
        return dist
    }
}

func main() {
    let g = Graph(vertices: 5)
    g.addEdge(u: 0, v: 1, w: -1)
    g.addEdge(u: 0, v: 2, w: 4)
    g.addEdge(u: 1, v: 2, w: 3)
    g.addEdge(u: 1, v: 3, w: 2)
    g.addEdge(u: 1, v: 4, w: 2)
    g.addEdge(u: 3, v: 2, w: 5)
    g.addEdge(u: 3, v: 1, w: 1)
    g.addEdge(u: 4, v: 3, w: -3)
    if let dist = g.bellmanFord(src: 0) {
        for i in 0..<g.V {
            print("\(i)\t\(dist[i])")
        }
    } else {
        print("Graph contains negative weight cycle")
    }
}

main()