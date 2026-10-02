class AbstractSyntaxTree {
    var value: Any
    var children: [AbstractSyntaxTree]

    init(value: Any, children: [AbstractSyntaxTree]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(child: AbstractSyntaxTree) {
        self.children.append(child)
    }

    func getChildren() -> [AbstractSyntaxTree] {
        return self.children
    }
}

class SemanticLint {
    var ast: AbstractSyntaxTree
    var errors: [String]

    init(ast: AbstractSyntaxTree) {
        self.ast = ast
        self.errors = []
    }

    func check() {
        self._traverse(node: ast)
    }

    private func _traverse(node: AbstractSyntaxTree) {
        if node == nil {
            return
        }
        self._analyzeNode(node: node)
        for child in node.getChildren() {
            self._traverse(node: child)
        }
    }

    private func _analyzeNode(node: AbstractSyntaxTree) {
        if !(node.value is String) {
            self.errors.append("Invalid node value: \(node.value)")
        }
        if node.children.count > 2 {
            self.errors.append("Too many children at node: \(node.value)")
        }
    }
}

func main() {
    let root = AbstractSyntaxTree(value: "root")
    let child1 = AbstractSyntaxTree(value: "child1")
    let child2 = AbstractSyntaxTree(value: "child2")
    let child3 = AbstractSyntaxTree(value: "child3")
    root.addChild(child: child1)
    root.addChild(child: child2)
    child1.addChild(child: child3)
    let lint = SemanticLint(ast: root)
    lint.check()
    if !lint.errors.isEmpty {
        print("Semantic linting errors found:")
        for error in lint.errors {
            print(error)
        }
    } else {
        print("No semantic linting errors found.")
    }
}

main()