func lintTree(_ node: Node?) {
    if node == nil {
        return
    }
    lintTree(node?.left)
    lintTree(node?.right)
    lintTree(node)
}

class Node {
    var left: Node?
    var right: Node?

    init(left: Node? = nil, right: Node? = nil) {
        self.left = left
        self.right = right
    }
}

let root = Node(left: Node(), right: Node(left: Node()))
lintTree(root)