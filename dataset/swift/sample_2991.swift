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

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func isBalanced(_ node: Node?) -> (Int, Bool) {
        if node == nil {
            return (0, true)
        }
        let leftHeight = isBalanced(node?.left).0
        let leftBalanced = isBalanced(node?.left).1
        let rightHeight = isBalanced(node?.right).0
        let rightBalanced = isBalanced(node?.right).1
        let balanced = leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1
        return (max(leftHeight, rightHeight) + 1, balanced)
    }

    func lint() -> (Int, Bool) {
        let height = isBalanced(root).0
        let balanced = isBalanced(root).1
        return (height, balanced)
    }
}

func generateSequence(_ n: Int) -> Node {
    if n == 0 {
        return Node(value: 0)
    }
    let left = generateSequence(n - 1)
    let right = generateSequence(n - 1)
    return Node(value: n, left: left, right: right)
}

func main() {
    while true {
        var n = 0
        let tree = Tree(root: generateSequence(n))
        let (height, balanced) = tree.lint()
        n += 1
    }
}

main()