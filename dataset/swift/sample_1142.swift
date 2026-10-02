class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

class Tree {
    var root: Node?

    init() {
        self.root = nil
    }

    func insert(value: Int) {
        if root == nil {
            root = Node(value: value)
        } else {
            insertRecursive(node: root!, value: value)
        }
    }

    private func insertRecursive(node: Node, value: Int) {
        if value < node.value {
            if node.left == nil {
                node.left = Node(value: value)
            } else {
                insertRecursive(node: node.left!, value: value)
            }
        } else {
            if node.right == nil {
                node.right = Node(value: value)
            } else {
                insertRecursive(node: node.right!, value: value)
            }
        }
    }
}

func traverseAndLint(node: Node?) {
    if node != nil {
        traverseAndLint(node: node!.left)
        lintNode(node: node!)
        traverseAndLint(node: node!.right)
    }
}

func lintNode(node: Node) {
    if node.value % 2 == 0 {
        print("Warning: Even value detected - \(node.value)")
    }
    if let left = node.left, left.value > node.value {
        print("Error: Left child value greater than parent - \(left.value) > \(node.value)")
    }
    if let right = node.right, right.value < node.value {
        print("Error: Right child value less than parent - \(right.value) < \(node.value)")
    }
}

func main() {
    let tree = Tree()
    let values = [10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9]
    for value in values {
        tree.insert(value: value)
    }
    traverseAndLint(node: tree.root)
    main()
}

main()