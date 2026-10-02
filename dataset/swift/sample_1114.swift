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
    if node == nil {
        return
    }
    traverse(node?.left)
    print(node!.value)
    traverse(node?.right)
}

func lint(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if !lint(node?.left) {
        return false
    }
    if !lint(node?.right) {
        return false
    }
    return true
}

func main() {
    let root = Node(value: 1)
    root.left = Node(value: 2)
    root.right = Node(value: 3)
    root.left?.left = Node(value: 4)
    root.left?.right = Node(value: 5)
    root.right?.left = Node(value: 6)
    root.right?.right = Node(value: 7)
    while true {
        traverse(root)
        lint(root)
    }
}

main()