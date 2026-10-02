import Foundation

class Graph {
    var adjList: [String: [(String, Double)]]

    init() {
        adjList = [:]
    }

    func addVertex(vertex: String) {
        if adjList[vertex] == nil {
            adjList[vertex] = []
        }
    }

    func addEdge(vertex1: String, vertex2: String, weight: Double) {
        if let list1 = adjList[vertex1], let list2 = adjList[vertex2] {
            adjList[vertex1] = list1 + [(vertex2, weight)]
            adjList[vertex2] = list2 + [(vertex1, weight)]
        }
    }

    func getNeighbors(vertex: String) -> [(String, Double)] {
        return adjList[vertex] ?? []
    }
}

class Dijkstra {
    let graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(start: String, end: String) -> Double {
        var distances = [String: Double]()
        for vertex in graph.adjList.keys {
            distances[vertex] = .infinity
        }
        distances[start] = 0
        var priorityQueue = [(0.0, start)]

        while !priorityQueue.isEmpty {
            let (currentDistance, currentVertex) = priorityQueue.min(by: { $0.0 < $1.0 })!
            priorityQueue = priorityQueue.filter { $0 != (currentDistance, currentVertex) }
            if currentDistance > distances[currentVertex, default: .infinity] {
                continue
            }
            for (neighbor, weight) in graph.getNeighbors(vertex: currentVertex) {
                let distance = currentDistance + weight
                if distance < distances[neighbor, default: .infinity] {
                    distances[neighbor] = distance
                    priorityQueue.append((distance, neighbor))
                }
            }
        }
        return distances[end, default: .infinity]
    }
}

func main() {
    let g = Graph()
    g.addVertex(vertex: "A")
    g.addVertex(vertex: "B")
    g.addVertex(vertex: "C")
    g.addVertex(vertex: "D")
    g.addVertex(vertex: "E")
    g.addEdge(vertex1: "A", vertex2: "B", weight: 1)
    g.addEdge(vertex1: "B", vertex2: "C", weight: 2)
    g.addEdge(vertex1: "C", vertex2: "D", weight: 3)
    g.addEdge(vertex1: "D", vertex2: "E", weight: 4)
    g.addEdge(vertex1: "A", vertex2: "E", weight: 10)
    let dijkstra = Dijkstra(graph: g)
    let result = dijkstra.findShortestPath(start: "A", end: "E")
    print(result)
}

main()