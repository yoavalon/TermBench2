class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(node: Node) {
        children.append(node)
    }
}

func lint(node: Node) -> [String] {
    var errors: [String] = []
    if node.value == "error" {
        errors.append("Error node found")
    }
    for child in node.children {
        errors.append(contentsOf: lint(node: child))
    }
    return errors
}

func analyze(tree: Node) {
    while true {
        let issues = lint(node: tree)
        if !issues.isEmpty {
            print("Issues found:", issues)
        } else {
            print("Tree is clean")
        }
    }
}

func main() {
    let root = Node(value: "ok")
    let child1 = Node(value: "error")
    let child2 = Node(value: "ok")
    root.addChild(node: child1)
    root.addChild(node: child2)
    analyze(tree: root)
}

main()