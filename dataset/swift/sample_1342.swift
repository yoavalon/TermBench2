class Node {
    var value: Int
    var children: [Node]

    init(value: Int, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }
}

func lint_tree(node: Node) -> [String] {
    var errors: [String] = []
    if node is Node {
        if node.children.isEmpty && node.value < 0 {
            errors.append("Negative value at node with value \(node.value)")
        }
        for child in node.children {
            errors.append(contentsOf: lint_tree(node: child))
        }
    }
    return errors
}

func main() {
    let tree = Node(value: 10, children: [Node(value: 5), Node(value: -3, children: [Node(value: 2), Node(value: -1)])])
    let errors = lint_tree(node: tree)
    if !errors.isEmpty {
        print("Linting Errors Found:")
        for error in errors {
            print(error)
        }
    } else {
        print("No linting errors found.")
    }
}

main()