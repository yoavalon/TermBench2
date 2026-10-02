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

func lint(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if let left = node?.left, !(left is Node) {
        return false
    }
    if let right = node?.right, !(right is Node) {
        return false
    }
    return lint(node?.left) && lint(node?.right)
}

func main() {
    let tree = Node(value: 1, left: Node(value: 2), right: Node(value: 3, left: Node(value: 4), right: Node(value: 5)))
    let result = lint(tree)
    print("Tree is valid:", result)
}

main()