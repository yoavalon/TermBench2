class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func traverse(node: Node, depth: Int) {
    if depth == 0 {
        return
    }
    for child in node.children {
        traverse(node: child, depth: depth - 1)
    }
}

func analyzeSyntaxTree(root: Node, maxDepth: Int) {
    traverse(node: root, depth: maxDepth)
}

func main() {
    let root = Node(value: "root", children: [Node(value: "child1"), Node(value: "child2", children: [Node(value: "grandchild1")])])
    analyzeSyntaxTree(root: root, maxDepth: 2)
}

main()