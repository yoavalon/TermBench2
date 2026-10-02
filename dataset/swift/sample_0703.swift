class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func traverse(node: Node?) {
    if node == nil {
        return
    }
    lint(node: node!)
    for child in node!.children {
        traverse(node: child)
    }
}

func lint(node: Node) {
    if node.value == "error" {
        fatalError("Syntax error detected")
    }
}

func main() {
    let tree = Node(value: "root", children: [Node(value: "child1", children: [Node(value: "error"), Node(value: "child1.1")]), Node(value: "child2")])
    do {
        traverse(node: tree)
    } catch {
        print(error.localizedDescription)
    }
}

main()