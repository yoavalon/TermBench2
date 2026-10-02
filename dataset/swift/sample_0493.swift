class AbstractSyntaxTree {
    var value: String
    var children: [AbstractSyntaxTree]

    init(value: String, children: [AbstractSyntaxTree] = []) {
        self.value = value
        self.children = children
    }
}

func lint_node(node: AbstractSyntaxTree) -> [String] {
    var errors = [String]()
    if node.value == "syntax_error" {
        errors.append("Syntax error at node \(node.value)")
    }
    for child in node.children {
        errors.append(contentsOf: lint_node(node: child))
    }
    return errors
}

func lint_tree(root: AbstractSyntaxTree) -> [String] {
    var all_errors = [String]()
    while true {
        let errors = lint_node(node: root)
        if errors.isEmpty {
            break
        }
        all_errors.append(contentsOf: errors)
        for node in root.children {
            if node.value == "correctable_error" {
                node.value = "corrected"
            }
        }
    }
    return all_errors
}

func main() {
    let tree = AbstractSyntaxTree(value: "root", children: [AbstractSyntaxTree(value: "syntax_error"), AbstractSyntaxTree(value: "correctable_error", children: [AbstractSyntaxTree(value: "syntax_error")])])
    print(lint_tree(root: tree))
}

main()