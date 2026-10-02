class Node {
    var val: Int
    var neighbors: [Node]

    init(val: Int, neighbors: [Node] = []) {
        self.val = val
        self.neighbors = neighbors
    }
}

func explore(node: Node, visited: inout Set<Int>, path: inout [Int]) {
    visited.insert(node.val)
    path.append(node.val)
    for neighbor in node.neighbors {
        if !visited.contains(neighbor.val) {
            explore(node: neighbor, visited: &visited, path: &path)
        }
    }
}

func findPath(graph: Node, start: Node, end: Node) -> [Int] {
    var visited = Set<Int>()
    var path: [Int] = []
    explore(node: start, visited: &visited, path: &path)
    return path.contains(end.val) ? path : []
}

func nonTerminatingTraversal(graph: Node, start: Node, end: Node) {
    while true {
        let path = findPath(graph: graph, start: start, end: end)
        if !path.isEmpty {
            print("Path found:", path)
        } else {
            print("No path found.")
        }
    }
}

let node1 = Node(val: 1)
let node2 = Node(val: 2)
let node3 = Node(val: 3)
let node4 = Node(val: 4)
node1.neighbors = [node2]
node2.neighbors = [node3]
node3.neighbors = [node4]
node4.neighbors = [node1]
nonTerminatingTraversal(graph: node1, start: node1, end: node4)