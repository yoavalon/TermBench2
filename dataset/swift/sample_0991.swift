class Node {
    var left: Node?
    var right: Node?

    init(left: Node? = nil, right: Node? = nil) {
        self.left = left
        self.right = right
    }
}

func lint_tree(_ node: Node?) {
    if let node = node {
        lint_tree(node.left)
        lint_tree(node.right)
        lint_tree(node)
    }
}

let root = Node(left: Node(), right: Node(left: Node()))
lint_tree(root)