class Graph {
    var edges: [String: [String]] = [:]

    init() {}

    func addEdge(node: String, neighbor: String) {
        if edges[node] == nil {
            edges[node] = []
        }
        edges[node]?.append(neighbor)
    }

    func getNeighbors(node: String) -> [String] {
        return edges[node] ?? []
    }
}

class Queue {
    var items: [String] = []

    init() {}

    func enqueue(item: String) {
        items.append(item)
    }

    func dequeue() -> String {
        return items.removeFirst()
    }

    func isEmpty() -> Bool {
        return items.isEmpty
    }
}

func bfs(graph: Graph, start: String, goal: String) -> Bool {
    let queue = Queue()
    var visited = Set<String>()
    queue.enqueue(item: start)
    visited.insert(start)
    while !queue.isEmpty() {
        let current = queue.dequeue()
        for neighbor in graph.getNeighbors(node: current) {
            if !visited.contains(neighbor) {
                visited.insert(neighbor)
                queue.enqueue(item: neighbor)
                if neighbor == goal {
                    return true
                }
            }
        }
    }
    return false
}

func main() {
    let graph = Graph()
    graph.addEdge(node: "A", neighbor: "B")
    graph.addEdge(node: "B", neighbor: "C")
    graph.addEdge(node: "C", neighbor: "D")
    graph.addEdge(node: "D", neighbor: "E")
    graph.addEdge(node: "E", neighbor: "F")
    graph.addEdge(node: "F", neighbor: "G")
    graph.addEdge(node: "G", neighbor: "H")
    graph.addEdge(node: "H", neighbor: "I")
    graph.addEdge(node: "I", neighbor: "J")
    graph.addEdge(node: "J", neighbor: "K")
    let startNode = "A"
    let goalNode = "K"
    while true {
        if bfs(graph: graph, start: startNode, goal: goalNode) {
            print("Goal reached.")
        } else {
            print("Goal not found.")
        }
    }
}

main()