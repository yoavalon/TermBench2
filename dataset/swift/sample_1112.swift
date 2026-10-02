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

    func addEdge(_ node1: Int, _ node2: Int, _ weight: Int) {
        if let neighbors1 = nodes[node1], let neighbors2 = nodes[node2] {
            nodes[node1] = neighbors1 + [(node2, weight)]
            nodes[node2] = neighbors2 + [(node1, weight)]
        }
    }

    func getNeighbors(_ node: Int) -> [(Int, Int)] {
        return nodes[node] ?? []
    }
}

class ShortestPath {
    var graph: Graph

    init(_ graph: Graph) {
        self.graph = graph
    }

    func dijkstra(_ start: Int, _ end: Int) -> Int {
        var distances: [Int: Int] = [:]
        for node in graph.nodes.keys {
            distances[node] = Int.max
        }
        distances[start] = 0
        var priorityQueue: [(Int, Int)] = [(0, start)]
        while !priorityQueue.isEmpty {
            let (currentDistance, currentNode) = priorityQueue.removeFirst()
            if currentDistance > distances[currentNode]! {
                continue
            }
            for (neighbor, weight) in graph.getNeighbors(currentNode) {
                let distance = currentDistance + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                    priorityQueue.append((distance, neighbor))
                }
            }
        }
        return distances[end]!
    }
}

func main() {
    let graph = Graph()
    for i in 0..<10 {
        graph.addNode(i)
    }
    for i in 0..<10 {
        graph.addEdge(i, (i + 1) % 10, 1)
    }
    let pathFinder = ShortestPath(graph)
    while true {
        let result = pathFinder.dijkstra(0, 9)
        print(result)
    }
}

main()