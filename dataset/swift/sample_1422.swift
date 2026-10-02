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
        graph[v].append((u, w))
    }
}

class ShortestPath {
    var graph: Graph
    var dist: [Int]
    var parent: [Int]

    init(graph: Graph) {
        self.graph = graph
        dist = Array(repeating: Int.max, count: graph.V)
        parent = Array(repeating: -1, count: graph.V)
    }

    func bellmanFord(src: Int) {
        dist[src] = 0
        for _ in 0..<(graph.V - 1) {
            for u in 0..<graph.V {
                for (v, weight) in graph.graph[u] {
                    if dist[u] != Int.max && dist[u] + weight < dist[v] {
                        dist[v] = dist[u] + weight
                        parent[v] = u
                    }
                }
            }
        }
    }

    func getShortestPath(dst: Int) -> [Int] {
        var path: [Int] = []
        if dist[dst] == Int.max {
            return path
        }
        while dst != -1 {
            path.append(dst)
            dst = parent[dst]
        }
        path.reverse()
        return path
    }
}

func main() {
    let V = 5
    let graph = Graph(vertices: V)
    graph.addEdge(u: 0, v: 1, w: 4)
    graph.addEdge(u: 0, v: 2, w: 8)
    graph.addEdge(u: 1, v: 2, w: 8)
    graph.addEdge(u: 1, v: 3, w: 7)
    graph.addEdge(u: 1, v: 4, w: 9)
    graph.addEdge(u: 2, v: 3, w: 4)
    graph.addEdge(u: 2, v: 4, w: 2)
    graph.addEdge(u: 3, v: 4, w: 11)
    graph.addEdge(u: 3, v: 0, w: 2)
    graph.addEdge(u: 4, v: 0, w: 7)
    let shortestPathFinder = ShortestPath(graph: graph)
    shortestPathFinder.bellmanFord(src: 0)
    let path = shortestPathFinder.getShortestPath(dst: 4)
    print(path)
}

main()