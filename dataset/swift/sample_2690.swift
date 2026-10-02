import Foundation

class Graph {
    var adjList: [String: [(String, Double)]] = [:]

    init() {}

    func addEdge(u: String, v: String, weight: Double) {
        if adjList[u] == nil {
            adjList[u] = []
        }
        if adjList[v] == nil {
            adjList[v] = []
        }
        adjList[u]?.append((v, weight))
        adjList[v]?.append((u, weight))
    }

    func dijkstra(start: String) -> [String: Double] {
        var distances: [String: Double] = [:]
        for vertex in adjList.keys {
            distances[vertex] = Double.greatestFiniteMagnitude
        }
        distances[start] = 0
        var priorityQueue: [(Double, String)] = [(0, start)]
        while !priorityQueue.isEmpty {
            let (currentDistance, currentVertex) = priorityQueue.removeFirst()
            if currentDistance > distances[currentVertex]! {
                continue
            }
            for (neighbor, weight) in adjList[currentVertex]! {
                let distance = currentDistance + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                    priorityQueue.append((distance, neighbor))
                    priorityQueue.sort { $0.0 < $1.0 }
                }
            }
        }
        return distances
    }
}

class PathFinder {
    let graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(start: String, end: String) -> Double {
        let distances = graph.dijkstra(start: start)
        return distances[end] ?? Double.greatestFiniteMagnitude
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "A", v: "C", weight: 4)
    graph.addEdge(u: "C", v: "D", weight: 3)
    graph.addEdge(u: "B", v: "D", weight: 5)
    let pathFinder = PathFinder(graph: graph)
    let result = pathFinder.findShortestPath(start: "A", end: "D")
    print(result)
}

main()