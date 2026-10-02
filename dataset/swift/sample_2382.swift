class AbstractSyntaxTree {
    var value: Any
    var children: [AbstractSyntaxTree]

    init(value: Any, children: [AbstractSyntaxTree] = []) {
        self.value = value
        self.children = children
    }

    func addChild(_ child: AbstractSyntaxTree) {
        children.append(child)
    }

    func traverse() -> AnyIterator<AbstractSyntaxTree> {
        var iterator = AnyIterator<AbstractSyntaxTree> {
            yield self
            for child in self.children {
                for node in child.traverse() {
                    yield node
                }
            }
            return nil
        }
        return iterator
    }
}

class SemanticLint {
    var tree: AbstractSyntaxTree

    init(tree: AbstractSyntaxTree) {
        self.tree = tree
    }

    func checkPrecision(_ node: AbstractSyntaxTree) -> Bool {
        if let value = node.value as? Double {
            let decimalPart = String(value).split(separator: ".")[1]
            return decimalPart.count <= 6
        }
        return true
    }

    func lint() {
        for node in tree.traverse() {
            if !checkPrecision(node) {
                print("Precision error at node with value: \(node.value)")
            }
        }
    }
}

func main() {
    let tree = AbstractSyntaxTree(value: "root")
    tree.addChild(AbstractSyntaxTree(value: 3.141592653589793))
    tree.addChild(AbstractSyntaxTree(value: 2.718281828459045))
    tree.addChild(AbstractSyntaxTree(value: "string"))
    let subTree = AbstractSyntaxTree(value: 1.4142135623730951)
    subTree.addChild(AbstractSyntaxTree(value: 0.5772156649015329))
    tree.addChild(subTree)
    let linter = SemanticLint(tree: tree)
    linter.lint()
    while true {
        // Non-terminating loop
    }
}

main()