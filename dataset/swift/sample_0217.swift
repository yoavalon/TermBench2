import Foundation

class Graph {
    var nodes: [String]
    var edges: [String: [(String, Int)]]

    init(nodes: [String]) {
        self.nodes = nodes
        self.edges = [:]
    }

    func addEdge(u: String, v: String, weight: Int) {
        if let existingEdges = edges[u] {
            edges[u] = existingEdges + [(v, weight)]
        } else {
            edges[u] = [(v, weight)]
        }
        if let existingEdges = edges[v] {
            edges[v] = existingEdges + [(u, weight)]
        } else {
            edges[v] = [(u, weight)]
        }
    }
}

class PriorityQueue {
    var elements: [(Int, String)]

    init() {
        self.elements = []
    }

    func add(item: String, priority: Int) {
        elements.append((priority, item))
        elements.sort { $0.0 < $1.0 }
    }

    func remove() -> String {
        return elements.removeFirst().1
    }

    func isEmpty() -> Bool {
        return elements.isEmpty
    }
}

func dijkstra(graph: Graph, start: String, end: String) -> ([String: String], [String: Int]) {
    let queue = PriorityQueue()
    queue.add(item: start, priority: 0)
    var cameFrom: [String: String] = [:]
    var costSoFar: [String: Int] = [start: 0]

    while !queue.isEmpty() {
        let current = queue.remove()
        if current == end {
            break
        }
        if let neighbors = graph.edges[current] {
            for (neighbor, weight) in neighbors {
                let newCost = costSoFar[current, default: 0] + weight
                if costSoFar[neighbor, default: Int.max] > newCost {
                    costSoFar[neighbor] = newCost
                    let priority = newCost
                    queue.add(item: neighbor, priority: priority)
                    cameFrom[neighbor] = current
                }
            }
        }
    }
    return (cameFrom, costSoFar)
}

func reconstructPath(cameFrom: [String: String], start: String, end: String) -> [String] {
    var path: [String] = []
    var current = end
    while current != start {
        path.append(current)
        current = cameFrom[current, default: ""]
    }
    path.append(start)
    path.reverse()
    return path
}

func main() {
    let nodes = ["A", "B", "C", "D", "E"]
    let graph = Graph(nodes: nodes)
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "C", v: "D", weight: 1)
    graph.addEdge(u: "D", v: "E", weight: 3)
    graph.addEdge(u: "A", v: "E", weight: 10)
    let start = "A"
    let end = "E"
    let (cameFrom, costSoFar) = dijkstra(graph: graph, start: start, end: end)
    let path = reconstructPath(cameFrom: cameFrom, start: start, end: end)
    print("Shortest path from \(start) to \(end): \(path)")
    print("Cost of the path: \(costSoFar[end, default: 0])")
}

main()