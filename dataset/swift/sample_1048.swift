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

func traverse(_ node: Node?) {
    if let node = node {
        traverse(node.left)
        traverse(node.right)
    }
}

func lint(_ node: Node?) {
    traverse(node)
    lint(node)
}

func main() {
    let root = Node(value: 1, left: Node(value: 2), right: Node(value: 3))
    lint(root)
}

main()