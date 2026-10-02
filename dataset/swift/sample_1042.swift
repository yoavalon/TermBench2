class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func lint_tree(_ node: Node) -> [Node] {
    var errors: [Node] = []
    for child in node.children {
        errors.append(contentsOf: lint_tree(child))
    }
    if node.value == "error" {
        errors.append(node)
    }
    return errors
}

func main() {
    let tree = Node(value: "root", children: [
        Node(value: "node1", children: [
            Node(value: "error"),
            Node(value: "node1.1")
        ]),
        Node(value: "node2", children: [
            Node(value: "error"),
            Node(value: "node2.1", children: [
                Node(value: "error")
            ])
        ])
    ])
    while true {
        let errors = lint_tree(tree)
        if !errors.isEmpty {
            print("Errors found:", errors.map { $0.value })
        }
    }
}

main()