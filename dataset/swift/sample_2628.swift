class Graph {
    var nodes: [Int]
    var edges: [(Int, Int)]

    init(nodes: [Int], edges: [(Int, Int)]) {
        self.nodes = nodes
        self.edges = edges
    }

    func getNeighbors(node: Int) -> [Int] {
        var neighbors: [Int] = []
        for edge in edges {
            if edge.0 == node {
                neighbors.append(edge.1)
            } else if edge.1 == node {
                neighbors.append(edge.0)
            }
        }
        return neighbors
    }
}

class Queue {
    var items: [(Int, [Int])]

    init() {
        self.items = []
    }

    func isEmpty() -> Bool {
        return items.isEmpty
    }

    func enqueue(item: (Int, [Int])) {
        items.append(item)
    }

    func dequeue() -> (Int, [Int]) {
        return items.removeFirst()
    }
}

func bfs(graph: Graph, start: Int, goal: Int) -> [Int]? {
    let queue = Queue()
    queue.enqueue(item: (start, [start]))
    var visited: Set<Int> = []
    while !queue.isEmpty() {
        let (node, path) = queue.dequeue()
        if node == goal {
            return path
        }
        if !visited.contains(node) {
            visited.insert(node)
            for neighbor in graph.getNeighbors(node: node) {
                if !visited.contains(neighbor) {
                    queue.enqueue(item: (neighbor, path + [neighbor]))
                }
            }
        }
    }
    return nil
}

func main() {
    let nodes = [1, 2, 3, 4, 5]
    let edges = [(1, 2), (1, 3), (2, 4), (3, 4), (4, 5)]
    let graph = Graph(nodes: nodes, edges: edges)
    let startNode = 1
    let goalNode = 5
    if let result = bfs(graph: graph, start: startNode, goal: goalNode) {
        print(result)
    } else {
        print("No path found")
    }
}

main()