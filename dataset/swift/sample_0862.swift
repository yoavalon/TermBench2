class Node {
    var name: String
    var neighbours: [Node] = []

    init(name: String) {
        self.name = name
    }

    func addNeighbour(node: Node) {
        neighbours.append(node)
    }
}

func findPath(start: Node, end: Node, visited: inout Set<Node>, path: inout [Node]) -> [Node]? {
    visited.insert(start)
    path.append(start)
    if start === end {
        return path
    }
    for neighbour in start.neighbours {
        if !visited.contains(neighbour) {
            if let result = findPath(start: neighbour, end: end, visited: &visited, path: &path) {
                return result
            }
        }
    }
    path.removeLast()
    return nil
}

func shortestPath(graph: [Node], startName: String, endName: String) -> [Node]? {
    var start: Node?
    var end: Node?
    for node in graph {
        if node.name == startName {
            start = node
        }
        if node.name == endName {
            end = node
        }
        if let _ = start, let _ = end {
            break
        }
    }
    if let start = start, let end = end {
        var visited = Set<Node>()
        var path: [Node] = []
        return findPath(start: start, end: end, visited: &visited, path: &path)
    }
    return nil
}

func main() {
    let a = Node(name: "A")
    let b = Node(name: "B")
    let c = Node(name: "C")
    let d = Node(name: "D")
    let e = Node(name: "E")
    let f = Node(name: "F")
    a.addNeighbour(node: b)
    a.addNeighbour(node: c)
    b.addNeighbour(node: d)
    c.addNeighbour(node: d)
    d.addNeighbour(node: e)
    e.addNeighbour(node: f)
    let graph = [a, b, c, d, e, f]
    if let path = shortestPath(graph: graph, startName: "A", endName: "F") {
        print(path.map { $0.name }.joined(separator: " -> "))
    } else {
        print("No path found")
    }
}

main()