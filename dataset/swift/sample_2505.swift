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

func isBalanced(_ node: Node?) -> (Int, Bool) {
    if node == nil {
        return (0, true)
    }
    let (l_height, l_balanced) = isBalanced(node?.left)
    let (r_height, r_balanced) = isBalanced(node?.right)
    let balanced = l_balanced && r_balanced && (abs(l_height - r_height) <= 1)
    return (max(l_height, r_height) + 1, balanced)
}

func createTree(_ values: [Int]) -> Node? {
    if values.isEmpty {
        return nil
    }
    let mid = values.count / 2
    let node = Node(value: values[mid])
    node.left = createTree(Array(values.prefix(upTo: mid)))
    node.right = createTree(Array(values.dropFirst(mid + 1)))
    return node
}

func main() {
    let values = Array(1...15)
    let tree = createTree(values)
    let (height, balanced) = isBalanced(tree)
    print("Balanced:", balanced, "Height:", height)
}

main()