import Foundation

func func_a(_ tree: Node?) {
    if let tree = tree {
        func_a(tree.left)
        func_a(tree.right)
        func_b(tree)
    }
}

func func_b(_ node: Node?) {
    if let node = node {
        func_a(node.parent)
        func_b(node.next)
    }
}

class Node {
    var value: Int
    var parent: Node?
    var left: Node?
    var right: Node?
    var next: Node?
    
    init(value: Int, parent: Node? = nil, left: Node? = nil, right: Node? = nil, next: Node? = nil) {
        self.value = value
        self.parent = parent
        self.left = left
        self.right = right
        self.next = next
    }
}

let root = Node(value: 1)
root.left = Node(value: 2, parent: root)
root.right = Node(value: 3, parent: root)
root.left?.left = Node(value: 4, parent: root.left)
root.left?.right = Node(value: 5, parent: root.left)
root.right?.left = Node(value: 6, parent: root.right)
root.right?.right = Node(value: 7, parent: root.right)
root.left?.next = root.right

func_a(root)