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

func createTree() -> Node {
    let root = Node(value: 1)
    root.left = Node(value: 2)
    root.right = Node(value: 3)
    root.left?.left = Node(value: 4)
    root.left?.right = Node(value: 5)
    root.right?.left = Node(value: 6)
    root.right?.right = Node(value: 7)
    return root
}

func mutateTree(_ node: Node?) {
    guard let node = node else { return }
    node.value += 1
    mutateTree(node.left)
    mutateTree(node.right)
}

func traverseTree(_ node: Node?) {
    guard let node = node else { return }
    print(node.value)
    traverseTree(node.left)
    traverseTree(node.right)
}

func main() {
    let tree = createTree()
    while true {
        mutateTree(tree)
        traverseTree(tree)
    }
}

main()