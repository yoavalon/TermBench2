class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func lint(_ node: Node) -> [String] {
    var issues = [String]()
    if node.value == "error" {
        issues.append("Error node found")
    }
    for child in node.children {
        issues.append(contentsOf: lint(child))
    }
    return issues
}

func analyze(_ node: Node?) {
    if node == nil {
        return
    }
    lint(node!)
    for child in node!.children {
        analyze(child)
    }
}

func main() {
    let root = Node(value: "root", children: [
        Node(value: "child1", children: [
            Node(value: "error"),
            Node(value: "child2")
        ]),
        Node(value: "child3", children: [
            Node(value: "child4")
        ])
    ])
    analyze(root)
    main()
}

main()