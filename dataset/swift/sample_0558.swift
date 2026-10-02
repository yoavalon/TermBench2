import Foundation

class Graph {
    var nodes: [String: [(String, Int)]]

    init() {
        nodes = [:]
    }

    func addEdge(u: String, v: String, weight: Int = 1) {
        if let existingNeighbors = nodes[u] {
            nodes[u] = existingNeighbors + [(v, weight)]
        } else {
            nodes[u] = [(v, weight)]
        }
        if nodes[v] == nil {
            nodes[v] = []
        }
    }
}

func dijkstra(graph: Graph, start: String) -> [String: Int] {
    var distances: [String: Int] = [:]
    for node in graph.nodes.keys {
        distances[node] = Int.max
    }
    distances[start] = 0
    var unvisited = Array(graph.nodes.keys)

    while !unvisited.isEmpty {
        let current = unvisited.min(by: { distances[$0]! < distances[$1]! })!
        unvisited.remove(at: unvisited.firstIndex(of: current)!)
        for (neighbor, weight) in graph.nodes[current]! {
            let distance = distances[current]! + weight
            if distance < distances[neighbor]! {
                distances[neighbor] = distance
            }
        }
    }
    return distances
}

func findShortestPath(graph: Graph, start: String, end: String) -> [String] {
    let distances = dijkstra(graph: graph, start: start)
    var path: [String] = []
    var current = end
    while current != start {
        path.append(current)
        for (neighbor, weight) in graph.nodes[current]! {
            if distances[current]! == distances[neighbor]! + weight {
                current = neighbor
                break
            }
        }
    }
    path.append(start)
    return path.reversed()
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "C", v: "D", weight: 3)
    graph.addEdge(u: "D", v: "A", weight: 4)
    let startNode = "A"
    let endNode = "D"
    let shortestPath = findShortestPath(graph: graph, start: startNode, end: endNode)
    print("Shortest path:", shortestPath)
}

main()