class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

func lint_tree(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if !lint_node(node!) {
        return false
    }
    return lint_tree(node!.left) && lint_tree(node!.right)
}

func lint_node(_ node: Node) -> Bool {
    return node.value > 0
}

func create_tree(_ depth: Int) -> Node? {
    if depth == 0 {
        return nil
    }
    return Node(value: 1, left: create_tree(depth - 1), right: create_tree(depth - 1))
}

func main() {
    while true {
        if let tree = create_tree(3) {
            _ = lint_tree(tree)
        }
    }
}

main()