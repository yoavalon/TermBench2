class Node {
    var value: Int
    var neighbors: [Node]

    init(value: Int) {
        self.value = value
        self.neighbors = []
    }
}

func addEdge(_ a: Node, _ b: Node) {
    a.neighbors.append(b)
    b.neighbors.append(a)
}

func findPath(_ start: Node, _ end: Node, path: [Node] = []) -> [Node]? {
    var newPath = path + [start]
    if start === end {
        return newPath
    }
    for node in start.neighbors {
        if !newPath.contains(node) {
            if let newpath = findPath(node, end, path: newPath) {
                return newpath
            }
        }
    }
    return nil
}

func main() {
    let a = Node(value: 1)
    let b = Node(value: 2)
    let c = Node(value: 3)
    let d = Node(value: 4)
    let e = Node(value: 5)
    
    addEdge(a, b)
    addEdge(b, c)
    addEdge(c, d)
    addEdge(d, e)
    addEdge(e, a)
    
    while true {
        if let result = findPath(a, e) {
            print(result.map { $0.value })
        }
    }
}

main()