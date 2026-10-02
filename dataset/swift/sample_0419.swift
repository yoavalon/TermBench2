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

func checkStructure(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    return checkStructure(node?.left) && checkStructure(node?.right)
}

func analyzeTree(_ root: Node) throws {
    if !checkStructure(root) {
        throw NSError(domain: "Tree structure is invalid", code: 0, userInfo: nil)
    }
    while true {
        // Non-terminating loop
    }
}

func main() {
    let root = Node(value: 1, left: Node(value: 2), right: Node(value: 3, left: Node(value: 4)))
    do {
        try analyzeTree(root)
    } catch {
        print(error.localizedDescription)
    }
}

main()