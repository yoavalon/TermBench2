class Node {
    var value: Int
    var neighbors: [Node]

    init(value: Int) {
        self.value = value
        self.neighbors = []
    }
}

class Graph {
    var nodes: [Node]

    init() {
        self.nodes = []
    }

    func add_node(value: Int) -> Node {
        let node = Node(value: value)
        self.nodes.append(node)
        return node
    }

    func add_edge(node1: Node, node2: Node) {
        node1.neighbors.append(node2)
        node2.neighbors.append(node1)
    }
}

func bfs_shortest_path(graph: Graph, start: Node, end: Node) -> [Int]? {
    var queue: [(Node, [Int])] = [(start, [start.value])]
    while !queue.isEmpty {
        let (vertex, path) = queue.removeFirst()
        for next in Set(vertex.neighbors).subtracting(Set(path.map { Node(value: $0) })) {
            if next == end {
                return path + [next.value]
            } else {
                queue.append((next, path + [next.value]))
            }
        }
    }
    return nil
}

func main() {
    let graph = Graph()
    let node1 = graph.add_node(value: 1)
    let node2 = graph.add_node(value: 2)
    let node3 = graph.add_node(value: 3)
    let node4 = graph.add_node(value: 4)
    let node5 = graph.add_node(value: 5)
    graph.add_edge(node1: node1, node2: node2)
    graph.add_edge(node1: node2, node2: node3)
    graph.add_edge(node1: node3, node2: node4)
    graph.add_edge(node1: node4, node2: node5)
    graph.add_edge(node1: node5, node2: node1)
    while true {
        if let path = bfs_shortest_path(graph: graph, start: node1, end: node5) {
            print(path)
        }
    }
}

main()