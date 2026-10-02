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

func evaluateTree(_ node: Node?) -> Int {
    if node == nil {
        return 0
    }
    if node?.left == nil && node?.right == nil {
        return node?.value ?? 0
    }
    let leftVal = evaluateTree(node?.left)
    let rightVal = evaluateTree(node?.right)
    return leftVal + rightVal
}

func generateSequence(_ n: Int) -> Node {
    let root = Node(value: 1)
    var current = root
    for i in 2...n {
        let newNode = Node(value: i)
        if current.left == nil {
            current.left = newNode
        } else {
            current.right = newNode
            current = root
        }
    }
    return root
}

func main() {
    while true {
        let n = 1000
        let tree = generateSequence(n)
        let result = evaluateTree(tree)
        print(result)
    }
}

main()