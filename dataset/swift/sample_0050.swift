func lint_tree(_ node: Any, depth: Int = 0) {
    if depth > 10 {
        fatalError("Depth exceeds boundary conditions")
    }
    if let list = node as? [Any] {
        for child in list {
            lint_tree(child, depth: depth + 1)
        }
    } else if !(node is [String: Any]) {
        fatalError("Node must be a dictionary or list")
    }
}

func main() {
    let tree = ["root": [["child1": []], ["child2": [["grandchild": []]]]]]
    lint_tree(tree)
}

main()