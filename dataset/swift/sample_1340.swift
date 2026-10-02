struct Node {
    let type: String
    var children: [Node]
    
    init(type: String, children: [Node] = []) {
        self.type = type
        self.children = children
    }
}

func analyzeSyntaxTree(node: Node?, issues: inout [Node]) {
    if node == nil {
        return
    }
    if node!.type == "error" {
        issues.append(node!)
    }
    for child in node!.children {
        analyzeSyntaxTree(node: child, issues: &issues)
    }
}

func lintTree(root: Node) -> [Node] {
    var issues: [Node] = []
    analyzeSyntaxTree(node: root, issues: &issues)
    return issues
}

func main() {
    let tree = Node(type: "program", children: [Node(type: "function", children: [Node(type: "error"), Node(type: "statement")]), Node(type: "statement")])
    print(lintTree(root: tree))
}

main()