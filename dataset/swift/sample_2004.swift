class Node {
    var value: Any
    var children: [Node]

    init(value: Any, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

class SyntaxTree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(node: Node) -> [Any] {
        if node == nil {
            return []
        }
        var results = [Any]()
        for child in node.children {
            results.append(contentsOf: traverse(node: child))
        }
        results.append(node.value)
        return results
    }
}

class Linter {
    var tree: SyntaxTree

    init(tree: SyntaxTree) {
        self.tree = tree
    }

    func lint() -> [Double] {
        let values = tree.traverse(node: tree.root)
        var issues = [Double]()
        for value in values {
            if let doubleValue = value as? Double, !doubleValue.isEqual(to: Double(round(doubleValue))) {
                issues.append(doubleValue)
            }
        }
        return issues
    }
}

func createTree() -> SyntaxTree {
    let n1 = Node(value: 1.0)
    let n2 = Node(value: 2.5)
    let n3 = Node(value: 3.0)
    let n4 = Node(value: 4.0)
    let n5 = Node(value: 5.5)
    n2.children = [n3, n4]
    n1.children = [n2, n5]
    return SyntaxTree(root: n1)
}

func main() {
    let tree = createTree()
    let linter = Linter(tree: tree)
    let issues = linter.lint()
    print("Floating point issues:", issues)
}

main()