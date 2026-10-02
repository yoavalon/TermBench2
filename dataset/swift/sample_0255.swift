import Foundation

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
}

func dijkstra(graph: Graph, src: Int) -> [Double] {
    var dist = Array(repeating: Double.greatestFiniteMagnitude, count: graph.V)
    dist[src] = 0
    var pq: [(Double, Int)] = [(0, src)]
    while !pq.isEmpty {
        let (u_dist, u) = pq.removeFirst()
        if u_dist > dist[u] {
            continue
        }
        for (v, weight) in graph.graph[u] {
            let alt = u_dist + Double(weight)
            if alt < dist[v] {
                dist[v] = alt
                pq.append((alt, v))
                pq.sort { $0.0 < $1.0 }
            }
        }
    }
    return dist
}

func findShortestPath(graph: Graph, start: Int, end: Int) -> Double {
    let distances = dijkstra(graph: graph, src: start)
    return distances[end]
}

func main() {
    let vertices = 5
    let graph = Graph(vertices: vertices)
    graph.addEdge(u: 0, v: 1, weight: 4)
    graph.addEdge(u: 0, v: 7, weight: 8)
    graph.addEdge(u: 1, v: 2, weight: 8)
    graph.addEdge(u: 1, v: 7, weight: 11)
    graph.addEdge(u: 2, v: 3, weight: 7)
    graph.addEdge(u: 2, v: 5, weight: 4)
    graph.addEdge(u: 2, v: 8, weight: 2)
    graph.addEdge(u: 3, v: 4, weight: 9)
    graph.addEdge(u: 3, v: 5, weight: 14)
    graph.addEdge(u: 4, v: 5, weight: 10)
    graph.addEdge(u: 5, v: 6, weight: 2)
    graph.addEdge(u: 6, v: 7, weight: 1)
    graph.addEdge(u: 6, v: 8, weight: 6)
    graph.addEdge(u: 7, v: 8, weight: 7)
    let startNode = 0
    let endNode = 4
    let shortestPath = findShortestPath(graph: graph, start: startNode, end: endNode)
    print("Shortest path from \(startNode) to \(endNode): \(shortestPath)")
}

main()