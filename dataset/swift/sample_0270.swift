import Foundation

class Graph {
    var edges: [Int: [(Int, Int)]]

    init() {
        self.edges = [:]
    }

    func addEdge(_ u: Int, _ v: Int, _ w: Int) {
        if let existingEdges = edges[u] {
            edges[u] = existingEdges + [(v, w)]
        } else {
            edges[u] = [(v, w)]
        }
    }

    func getNeighbors(_ u: Int) -> [(Int, Int)] {
        return edges[u] ?? []
    }
}

class Dijkstra {
    var graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(_ start: Int, _ end: Int) -> [Int]? {
        var q: [(Int, Int, [Int])] = [(0, start, [])]
        var dist: [Int: Int] = [start: 0]
        var visited = Set<Int>()

        while !q.isEmpty {
            let (cost, node, path) = q.removeFirst()
            if visited.contains(node) {
                continue
            }
            visited.insert(node)
            let newPath = path + [node]
            if node == end {
                return newPath
            }
            for (neighbor, weight) in graph.getNeighbors(node) {
                if !visited.contains(neighbor) {
                    let newCost = cost + weight
                    q.append((newCost, neighbor, newPath))
                    q.sort { $0.0 < $1.0 }
                }
            }
        }
        return nil
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(1, 2, 7)
    graph.addEdge(1, 3, 9)
    graph.addEdge(2, 3, 10)
    graph.addEdge(2, 4, 15)
    graph.addEdge(3, 4, 11)
    graph.addEdge(4, 5, 6)
    let dijkstra = Dijkstra(graph)
    if let result = dijkstra.findShortestPath(1, 5) {
        print(result)
    }
}

main()