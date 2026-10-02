class Node {
    var data: Int
    var neighbors: [Node] = []

    init(data: Int) {
        self.data = data
    }

    func add_neighbor(neighbor: Node) {
        neighbors.append(neighbor)
    }
}

func build_graph() -> Node {
    var nodes = [Node]()
    for i in 0..<10 {
        nodes.append(Node(data: i))
    }
    for i in 0..<(nodes.count - 1) {
        nodes[i].add_neighbor(neighbor: nodes[i + 1])
        nodes[i + 1].add_neighbor(neighbor: nodes[i])
    }
    return nodes[0]
}

func find_shortest_path(start: Node, end: Node, visited: Set<Node>) -> [Int]? {
    var visited = visited
    visited.insert(start)
    if start === end {
        return [end.data]
    }
    for neighbor in start.neighbors {
        if !visited.contains(neighbor) {
            if let path = find_shortest_path(start: neighbor, end: end, visited: visited) {
                return [start.data] + path
            }
        }
    }
    return nil
}

func main() {
    let start_node = build_graph()
    let end_node = start_node
    while true {
        if let path = find_shortest_path(start: start_node, end: end_node, visited: []) {
            print(path)
        } else {
            print("No path found")
        }
    }
}

main()