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

func lint_tree(_ node: Node?) -> Int {
    if node == nil {
        return 0
    }
    let left_depth = lint_tree(node?.left)
    let right_depth = lint_tree(node?.right)
    if abs(left_depth - right_depth) > 1 {
        fatalError("Unbalanced tree detected")
    }
    return max(left_depth, right_depth) + 1
}

func generate_sequence() {
    let root = Node(value: 0)
    var current = root
    while true {
        current.left = Node(value: current.value + 1)
        current.right = Node(value: current.value + 2)
        current = current.right!
    }
}

func main() {
    generate_sequence()
}

main()