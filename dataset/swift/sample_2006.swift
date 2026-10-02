class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse() -> [String] {
        var result: [String] = []
        _traverseHelper(node: root, accumulator: &result)
        return result
    }

    private func _traverseHelper(node: Node, accumulator: inout [String]) {
        if node != nil {
            accumulator.append(node.value)
            for child in node.children {
                _traverseHelper(node: child, accumulator: &accumulator)
            }
        }
    }
}

class SemanticLint {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func check() -> [String] {
        var issues: [String] = []
        _checkHelper(node: tree.root, issues: &issues)
        return issues
    }

    private func _checkHelper(node: Node, issues: inout [String]) {
        if node != nil {
            if _isFloatingPoint(value: node.value) {
                if !_hasHighPrecision(value: node.value) {
                    issues.append("Low precision for \(node.value)")
                }
            }
            for child in node.children {
                _checkHelper(node: child, issues: &issues)
            }
        }
    }

    private func _isFloatingPoint(value: String) -> Bool {
        if let _ = Double(value) {
            return true
        }
        return false
    }

    private func _hasHighPrecision(value: String) -> Bool {
        guard let doubleValue = Double(value) else { return false }
        return abs(doubleValue - (doubleValue.rounded(to: 10))) < 1e-09
    }
}

func main() {
    let root = Node(value: "1.0")
    let child1 = Node(value: "0.1")
    let child2 = Node(value: "0.0000000001")
    root.addChild(child: child1)
    root.addChild(child: child2)
    let tree = Tree(root: root)
    let lint = SemanticLint(tree: tree)
    print(lint.check())
}

main()