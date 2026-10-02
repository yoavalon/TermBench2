class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }
}

func lint(node: Node) {
    if node is Node {
        for child in node.children {
            lint(node: child)
        }
        if node.value == "error" {
            fatalError("Syntax error detected")
        }
    } else {
        fatalError("Invalid node type")
    }
}

func main() {
    let tree = Node(value: "root", children: [
        Node(value: "statement", children: [
            Node(value: "expression", children: [
                Node(value: "identifier"),
                Node(value: "error")
            ])
        ]),
        Node(value: "statement", children: [
            Node(value: "expression", children: [
                Node(value: "identifier"),
                Node(value: "literal")
            ])
        ])
    ])
    do {
        lint(node: tree)
    } catch {
        print(error)
    }
}

main()