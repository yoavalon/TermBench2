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

func validate_tree(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if let left = node?.left, node?.value <= left.value {
        return false
    }
    if let right = node?.right, node?.value >= right.value {
        return false
    }
    return validate_tree(node?.left) && validate_tree(node?.right)
}

func build_sequence(_ length: Int) -> Node? {
    if length == 0 {
        return nil
    }
    let root = Node(value: 1)
    var current = root
    for i in 2...length {
        if current.left == nil {
            current.left = Node(value: i)
            current = current.left!
        } else if current.right == nil {
            current.right = Node(value: i)
            current = root
        }
    }
    return root
}

func analyze_sequence(_ root: Node?) -> [Int]? {
    if !validate_tree(root) {
        return nil
    }
    var sequence: [Int] = []
    var stack: [Node] = []
    if let root = root {
        stack.append(root)
    }
    while !stack.isEmpty {
        let node = stack.removeLast()
        sequence.append(node.value)
        if let right = node.right {
            stack.append(right)
        }
        if let left = node.left {
            stack.append(left)
        }
    }
    return sequence
}

func main() {
    let length = 10
    let root = build_sequence(length)
    if let result = analyze_sequence(root) {
        print("Valid sequence:", result)
    } else {
        print("Invalid sequence")
    }
}

main()