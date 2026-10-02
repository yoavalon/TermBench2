import Foundation

class Graph {
    var nodes: [Int: [(Int, Int)]]

    init() {
        nodes = [:]
    }

    func addNode(_ node: Int) {
        if nodes[node] == nil {
            nodes[node] = []
        }
    }

    func addEdge(_ node1: Int, _ node2: Int, weight: Int = 1) {
        if let neighbors1 = nodes[node1], let neighbors2 = nodes[node2] {
            nodes[node1] = neighbors1 + [(node2, weight)]
            nodes[node2] = neighbors2 + [(node1, weight)]
        }
    }

    func getNeighbors(_ node: Int) -> [(Int, Int)] {
        return nodes[node] ?? []
    }
}

class PathFinder {
    var graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func dijkstra(_ start: Int, _ end: Int) -> Int? {
        var distances: [Int: Int] = [:]
        for node in graph.nodes.keys {
            distances[node] = Int.max
        }
        distances[start] = 0
        var priorityQueue = [(0, start)]
        while !priorityQueue.isEmpty {
            let (currentDistance, currentNode) = priorityQueue.min(by: { $0.0 < $1.0 })!
            priorityQueue.removeAll { $0 == (currentDistance, currentNode) }
            if currentNode == end {
                return distances[end]
            }
            for (neighbor, weight) in graph.getNeighbors(currentNode) {
                let distance = currentDistance + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                    priorityQueue.append((distance, neighbor))
                }
            }
        }
        return nil
    }
}

class SequenceGenerator {
    var graph: Graph
    var pathFinder: PathFinder

    init(_ graph: Graph, _ pathFinder: PathFinder) {
        self.graph = graph
        self.pathFinder = pathFinder
    }

    func generateSequence() -> Int? {
        let startNode = graph.nodes.keys.randomElement()!
        var endNode = graph.nodes.keys.randomElement()!
        while endNode == startNode {
            endNode = graph.nodes.keys.randomElement()!
        }
        return pathFinder.dijkstra(startNode, endNode)
    }
}

func main() {
    let graph = Graph()
    let nodes = Array(0..<10)
    for node in nodes {
        graph.addNode(node)
    }
    for i in 0..<10 {
        for j in i + 1..<10 {
            graph.addEdge(i, j, weight: Int.random(in: 1...10))
        }
    }
    let pathFinder = PathFinder(graph)
    let sequenceGenerator = SequenceGenerator(graph, pathFinder)
    while true {
        if let sequence = sequenceGenerator.generateSequence() {
            print(sequence)
        }
    }
}

main()