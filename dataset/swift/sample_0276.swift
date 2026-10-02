class Node {
    var value: Int
    var children: [Node] = []

    init(value: Int) {
        self.value = value
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

func validateTreeStructure(node: Node, maxDepth: Int, currentDepth: Int = 0) throws {
    if currentDepth > maxDepth {
        throw NSError(domain: "", code: 1, userInfo: [NSLocalizedDescriptionKey: "Tree exceeds maximum depth"])
    }
    for child in node.children {
        try validateTreeStructure(node: child, maxDepth: maxDepth, currentDepth: currentDepth + 1)
    }
}

func analyzeSyntaxTree(root: Node, maxNodes: Int) throws {
    var nodeCount = 0

    func traverse(node: Node) throws {
        nodeCount += 1
        if nodeCount > maxNodes {
            throw NSError(domain: "", code: 1, userInfo: [NSLocalizedDescriptionKey: "Exceeded maximum number of nodes"])
        }
        for child in node.children {
            try traverse(node: child)
        }
    }

    try traverse(node: root)
    if nodeCount < maxNodes {
        throw NSError(domain: "", code: 1, userInfo: [NSLocalizedDescriptionKey: "Insufficient number of nodes"])
    }
}

func main() {
    let root = Node(value: 1)
    let child1 = Node(value: 2)
    let child2 = Node(value: 3)
    root.addChild(child: child1)
    root.addChild(child: child2)
    child1.addChild(child: Node(value: 4))
    child2.addChild(child: Node(value: 5))
    child2.addChild(child: Node(value: 6))

    do {
        try validateTreeStructure(node: root, maxDepth: 3)
        try analyzeSyntaxTree(root: root, maxNodes: 6)
        print("Tree structure is valid.")
    } catch {
        print("Tree structure error: \(error.localizedDescription)")
    }
}

main()