import Foundation

class Graph {
    var nodes: [String: [String: Int]] = [:]

    init() {}

    func addEdge(u: String, v: String, weight: Int) {
        if nodes[u] == nil {
            nodes[u] = [:]
        }
        if nodes[v] == nil {
            nodes[v] = [:]
        }
        nodes[u]![v] = weight
        nodes[v]![u] = weight
    }

    func getNeighbors(node: String) -> [String: Int] {
        return nodes[node] ?? [:]
    }
}

class PriorityQueue {
    var elements: [(Int, String)] = []

    init() {}

    func add(item: String, priority: Int) {
        elements.append((priority, item))
        elements.sort { $0.0 < $1.0 }
    }

    func get() -> String? {
        return elements.isEmpty ? nil : elements.removeFirst().1
    }

    func isEmpty() -> Bool {
        return elements.isEmpty
    }
}

func dijkstra(graph: Graph, start: String, end: String) -> [String] {
    let queue = PriorityQueue()
    queue.add(item: start, priority: 0)
    var distances: [String: Int] = [:]
    for node in graph.nodes.keys {
        distances[node] = Int.max
    }
    distances[start] = 0
    var previousNodes: [String: String?] = [:]
    for node in graph.nodes.keys {
        previousNodes[node] = nil
    }
    while !queue.isEmpty() {
        if let current = queue.get() {
            if current == end {
                break
            }
            for (neighbor, weight) in graph.getNeighbors(node: current) {
                let distance = distances[current]! + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                    previousNodes[neighbor] = current
                    queue.add(item: neighbor, priority: distance)
                }
            }
        }
    }
    var path: [String] = []
    var current = end
    while let _ = previousNodes[current] {
        path.append(current)
        current = previousNodes[current]!
    }
    path.append(start)
    path.reverse()
    return path
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "A", v: "C", weight: 4)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "B", v: "D", weight: 5)
    graph.addEdge(u: "C", v: "D", weight: 1)
    graph.addEdge(u: "D", v: "E", weight: 3)
    let startNode = "A"
    let endNode = "E"
    let result = dijkstra(graph: graph, start: startNode, end: endNode)
    print(result)
}

main()