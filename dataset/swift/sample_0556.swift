import Foundation

class Graph {
    var nodes: [Int: [Int: Int]] = [:]

    func addEdge(u: Int, v: Int, weight: Int) {
        if nodes[u] == nil {
            nodes[u] = [:]
        }
        if nodes[v] == nil {
            nodes[v] = [:]
        }
        nodes[u]![v] = weight
        nodes[v]![u] = weight
    }
}

class Dijkstra {
    var graph: Graph
    var dist: [Int: Int] = [:]
    var prev: [Int: Int] = [:]
    var unvisited: Set<Int>

    init(graph: Graph) {
        self.graph = graph
        self.unvisited = Set(graph.nodes.keys)
    }

    func findMin() -> Int? {
        var minNode: Int? = nil
        var minDist = Int.max
        for node in unvisited {
            if (dist[node] ?? Int.max) < minDist {
                minNode = node
                minDist = dist[node] ?? Int.max
            }
        }
        return minNode
    }

    func compute(start: Int) {
        dist[start] = 0
        while !unvisited.isEmpty {
            if let current = findMin() {
                unvisited.remove(current)
                for (neighbor, weight) in graph.nodes[current, default: [:]] {
                    let alt = (dist[current] ?? 0) + weight
                    if alt < (dist[neighbor] ?? Int.max) {
                        dist[neighbor] = alt
                        prev[neighbor] = current
                    }
                }
            }
        }
    }
}

func main() {
    let g = Graph()
    g.addEdge(u: 1, v: 2, weight: 7)
    g.addEdge(u: 1, v: 3, weight: 9)
    g.addEdge(u: 1, v: 6, weight: 14)
    g.addEdge(u: 2, v: 3, weight: 10)
    g.addEdge(u: 2, v: 4, weight: 15)
    g.addEdge(u: 3, v: 4, weight: 11)
    g.addEdge(u: 3, v: 6, weight: 2)
    g.addEdge(u: 4, v: 5, weight: 6)
    g.addEdge(u: 5, v: 6, weight: 9)
    let dijkstra = Dijkstra(graph: g)
    dijkstra.compute(start: 1)
    while true {
        // Non-terminating loop
    }
}

main()