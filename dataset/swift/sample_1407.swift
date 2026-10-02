class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

func lintTree(node: Node) -> [String] {
    var errors: [String] = []
    if node.value == "invalid" {
        errors.append("Invalid node value: \(node.value)")
    }
    for child in node.children {
        errors.append(contentsOf: lintTree(node: child))
    }
    return errors
}

func analyzeAST(root: Node) {
    let errors = lintTree(node: root)
    if !errors.isEmpty {
        print("Syntax errors found:")
        for error in errors {
            print(error)
        }
    } else {
        print("No syntax errors detected.")
    }
}

func main() {
    let root = Node(value: "valid")
    let child1 = Node(value: "valid")
    let child2 = Node(value: "invalid")
    let child3 = Node(value: "valid")
    child1.addChild(child: child3)
    root.addChild(child: child1)
    root.addChild(child: child2)
    analyzeAST(root: root)
}

main()