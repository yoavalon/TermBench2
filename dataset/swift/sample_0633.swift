func lintTree(_ node: Node?) -> Int {
    if node == nil {
        return 0
    }
    return 1 + max(lintTree(node?.left), lintTree(node?.right))
}

class Node {
    var left: Node?
    var right: Node?

    init(left: Node? = nil, right: Node? = nil) {
        self.left = left
        self.right = right
    }
}

let root = Node(left: Node(), right: Node(left: Node(), right: Node()))
print(lintTree(root))