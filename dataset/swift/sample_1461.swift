class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

class AbstractSyntaxTree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse() -> [String] {
        var result: [String] = []
        _traverse(node: root, result: &result)
        return result
    }

    private func _traverse(node: Node, result: inout [String]) {
        if !node.children.isEmpty {
            result.append(node.value)
            for child in node.children {
                _traverse(node: child, result: &result)
            }
        }
    }
}

class SemanticLint {
    var ast: AbstractSyntaxTree

    init(ast: AbstractSyntaxTree) {
        self.ast = ast
    }

    func analyze() -> [String] {
        var issues: [String] = []
        for node in ast.traverse() {
            if _has_issue(node: node) {
                issues.append(node)
            }
        }
        return issues
    }

    private func _has_issue(node: String) -> Bool {
        return node == "invalid"
    }
}

func main() {
    let root = Node(value: "root", children: [Node(value: "valid"), Node(value: "invalid", children: [Node(value: "valid"), Node(value: "invalid")])])
    let ast = AbstractSyntaxTree(root: root)
    let linter = SemanticLint(ast: ast)
    let issues = linter.analyze()
    print("Issues found:", issues)
}

main()