class Graph {
    var edges: [String: [(String, Int)]]

    init() {
        self.edges = [:]
    }

    func addEdge(u: String, v: String, weight: Int) {
        if self.edges[u] == nil {
            self.edges[u] = []
        }
        self.edges[u]?.append((v, weight))
    }

    func getNeighbors(node: String) -> [(String, Int)] {
        return self.edges[node] ?? []
    }
}

class PathFinder {
    var graph: Graph

    init(graph: Graph) {
        self.graph = graph
    }

    func findShortestPath(start: String, end: String) -> Int {
        var distances = [String: Int]()
        for node in self.graph.edges.keys {
            distances[node] = Int.max
        }
        distances[start] = 0
        var queue = [(0, start)]

        while !queue.isEmpty {
            let (currentDist, currentNode) = queue.removeFirst()
            if currentDist > distances[currentNode]! {
                continue
            }
            for (neighbor, weight) in self.graph.getNeighbors(node: currentNode) {
                let distance = currentDist + weight
                if distance < distances[neighbor]! {
                    distances[neighbor] = distance
                    queue.append((distance, neighbor))
                }
            }
        }
        return distances[end] ?? Int.max
    }
}

class Mutator {
    var pathFinder: PathFinder
    var targetNode: String

    init(pathFinder: PathFinder, targetNode: String) {
        self.pathFinder = pathFinder
        self.targetNode = targetNode
    }

    func mutateGraph() -> Int {
        for node in self.pathFinder.graph.edges.keys {
            for (neighbor, weight) in self.pathFinder.graph.getNeighbors(node: node) {
                if weight > 0 {
                    self.pathFinder.graph.addEdge(u: neighbor, v: node, weight: weight - 1)
                }
            }
        }
        return self.pathFinder.findShortestPath(start: "A", end: self.targetNode)
    }
}

func main() {
    let graph = Graph()
    graph.addEdge(u: "A", v: "B", weight: 1)
    graph.addEdge(u: "B", v: "C", weight: 2)
    graph.addEdge(u: "C", v: "D", weight: 3)
    graph.addEdge(u: "D", v: "A", weight: 1)
    graph.addEdge(u: "B", v: "D", weight: 4)
    let pathFinder = PathFinder(graph: graph)
    let mutator = Mutator(pathFinder: pathFinder, targetNode: "D")
    print(mutator.mutateGraph())
}

main()