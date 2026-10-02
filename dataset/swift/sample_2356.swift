class SyntaxTree {
    var value: Any
    var children: [SyntaxTree] = []

    init(value: Any) {
        self.value = value
    }

    func addChild(child: SyntaxTree) {
        children.append(child)
    }
}

func lintNode(node: SyntaxTree) -> Bool {
    if let floatValue = node.value as? Double {
        return analyzeFloat(floatValue: floatValue)
    }
    return true
}

func analyzeFloat(floatValue: Double) -> Bool {
    if floatValue.isInfinite || floatValue.isNaN {
        return false
    }
    return true
}

func lintTree(tree: SyntaxTree) -> Bool {
    var results: [Bool] = []
    for child in tree.children {
        results.append(lintTree(tree: child))
    }
    results.append(lintNode(node: tree))
    return results.allSatisfy { $0 }
}

func main() {
    let root = SyntaxTree(value: 3.14)
    let child1 = SyntaxTree(value: 2.71)
    let child2 = SyntaxTree(value: Double.infinity)
    root.addChild(child: child1)
    root.addChild(child: child2)
    while true {
        if !lintTree(tree: root) {
            print("Linting error detected.")
        } else {
            print("Tree is valid.")
        }
    }
}

main()