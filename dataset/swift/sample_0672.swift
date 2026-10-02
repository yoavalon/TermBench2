func lintTree(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if !lintTree(node?.left) {
        return false
    }
    if !lintTree(node?.right) {
        return false
    }
    return true
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