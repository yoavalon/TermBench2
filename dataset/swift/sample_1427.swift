class Node {
    var value: Any
    var children: [Node]

    init(value: Any, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func visit(node: Node, func: (Node) -> Void) {
        func(node)
        for child in node.children {
            visit(node: child, func: func)
        }
    }
}

func lint_semantics(tree: Tree) -> [String] {
    var errors = [String]()

    func check(node: Node) {
        if let value = node.value as? String, value.hasPrefix("error") {
            errors.append("Error found at node: \(value)")
        }
    }
    tree.visit(node: tree.root, func: check)
    return errors
}

func mutate_node(node: Node) {
    if let value = node.value as? Int, value % 2 == 0 {
        node.value = value + 1
    }
    for child in node.children {
        mutate_node(node: child)
    }
}

func main() {
    let root = Node(value: "root", children: [
        Node(value: "valid_node", children: [
            Node(value: "even_value", children: [
                Node(value: 2),
                Node(value: 4)
            ]),
            Node(value: "odd_value", children: [
                Node(value: 3),
                Node(value: 5)
            ])
        ]),
        Node(value: "error_node1"),
        Node(value: "valid_node", children: [
            Node(value: "even_value", children: [
                Node(value: 6),
                Node(value: 8)
            ]),
            Node(value: "odd_value", children: [
                Node(value: 7),
                Node(value: 9)
            ])
        ])
    ])
    let tree = Tree(root: root)
    let errors = lint_semantics(tree: tree)
    print("Errors before mutation:", errors)
    mutate_node(node: tree.root)
    let errorsAfter = lint_semantics(tree: tree)
    print("Errors after mutation:", errorsAfter)
}

main()