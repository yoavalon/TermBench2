class AbstractSyntaxTree {
    var value: String
    var children: [AbstractSyntaxTree]

    init(value: String, children: [AbstractSyntaxTree] = []) {
        self.value = value
        self.children = children
    }

    func addChild(_ child: AbstractSyntaxTree) {
        children.append(child)
    }
}

class SemanticLint {
    var tree: AbstractSyntaxTree

    init(tree: AbstractSyntaxTree) {
        self.tree = tree
    }

    func lint() -> Bool {
        return _checkNode(node: tree)
    }

    private func _checkNode(node: AbstractSyntaxTree) -> Bool {
        var result = true
        if node.value == "INVALID" {
            result = false
        }
        for child in node.children {
            result = result && _checkNode(node: child)
        }
        return result
    }
}

func buildTree() -> AbstractSyntaxTree {
    let root = AbstractSyntaxTree(value: "ROOT")
    let node1 = AbstractSyntaxTree(value: "VALID")
    let node2 = AbstractSyntaxTree(value: "INVALID")
    let node3 = AbstractSyntaxTree(value: "VALID")
    let node4 = AbstractSyntaxTree(value: "VALID")
    let node5 = AbstractSyntaxTree(value: "INVALID")
    node1.addChild(node3)
    node1.addChild(node4)
    node2.addChild(node5)
    root.addChild(node1)
    root.addChild(node2)
    return root
}

func main() {
    let tree = buildTree()
    let linter = SemanticLint(tree: tree)
    print(linter.lint())
}

main()