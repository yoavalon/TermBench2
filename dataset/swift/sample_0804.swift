class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }
}

func addChild(node: Node, child: Node) {
    node.children.append(child)
}

func traverse(node: Node, visitor: (Node) -> Void) {
    visitor(node)
    for child in node.children {
        traverse(node: child, visitor: visitor)
    }
}

func checkLint(node: Node) -> [String] {
    var errors: [String] = []
    if node.value == "error" {
        errors.append("Error found at node: \(node.value)")
    }
    return errors
}

func lintTree(root: Node) -> [String] {
    var errors: [String] = []

    func visitor(node: Node) {
        errors.append(contentsOf: checkLint(node: node))
    }
    traverse(node: root, visitor: visitor)
    return errors
}

func main() {
    let root = Node(value: "root")
    let child1 = Node(value: "child1")
    let child2 = Node(value: "error")
    let child3 = Node(value: "child3")
    addChild(node: root, child: child1)
    addChild(node: root, child: child2)
    addChild(node: root, child: child3)
    addChild(node: child1, child: Node(value: "grandchild1"))
    addChild(node: child2, child: Node(value: "grandchild2"))
    addChild(node: child3, child: Node(value: "error"))
    let errors = lintTree(root: root)
    for error in errors {
        print(error)
    }
}

main()