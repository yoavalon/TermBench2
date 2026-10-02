import Foundation

class Graph {
    var adjList: [String: [(String, Double)]]

    init() {
        adjList = [:]
    }

    func addVertex(_ vertex: String) {
        if adjList[vertex] == nil {
            adjList[vertex] = []
        }
    }

    func addEdge(_ vertex1: String, _ vertex2: String, _ weight: Double) {
        if let _ = adjList[vertex1], let _ = adjList[vertex2] {
            adjList[vertex1]?.append((vertex2, weight))
            adjList[vertex2]?.append((vertex1, weight))
        }
    }

    func getNeighbors(_ vertex: String) -> [(String, Double)] {
        return adjList[vertex] ?? []
    }
}

class PriorityQueue {
    var elements: [(Double, String)]

    init() {
        elements = []
    }

    func isEmpty() -> Bool {
        return elements.isEmpty
    }

    func put(_ item: String, _ priority: Double) {
        elements.append((priority, item))
        elements.sort { $0.0 < $1.0 }
    }

    func get() -> String {
        return elements.removeFirst().1
    }
}

func dijkstra(_ graph: Graph, _ start: String, _ end: String) -> ([String], [String: Double]) {
    let queue = PriorityQueue()
    queue.put(start, 0)
    var distances = [String: Double]()
    for vertex in graph.adjList.keys {
        distances[vertex] = Double.greatestFiniteMagnitude
    }
    distances[start] = 0
    var previous = [String: String?]()
    for vertex in graph.adjList.keys {
        previous[vertex] = nil
    }
    while !queue.isEmpty() {
        let current = queue.get()
        if current == end {
            break
        }
        for (neighbor, weight) in graph.getNeighbors(current) {
            let distance = distances[current]! + weight
            if distance < distances[neighbor]! {
                distances[neighbor] = distance
                previous[neighbor] = current
                queue.put(neighbor, distance)
            }
        }
    }
    var path: [String] = []
    var current = end
    while current != nil {
        path.append(current)
        current = previous[current]!
    }
    return (path.reversed(), distances)
}

func main() {
    let graph = Graph()
    let vertices = ["A", "B", "C", "D", "E"]
    for vertex in vertices {
        graph.addVertex(vertex)
    }
    graph.addEdge("A", "B", 1)
    graph.addEdge("B", "C", 2)
    graph.addEdge("C", "D", 3)
    graph.addEdge("D", "E", 4)
    graph.addEdge("E", "A", 5)
    let (path, distances) = dijkstra(graph, "A", "E")
    print("Path:", path)
    print("Distances:", distances)
}

main()