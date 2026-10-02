class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }
}

func validate(node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if !(node is Node) {
        return false
    }
    if !(node?.children is [Node]) {
        return false
    }
    for child in node?.children ?? [] {
        if !validate(node: child) {
            return false
        }
    }
    return true
}

func analyze(node: Node?, issues: inout [String]) {
    if issues == nil {
        issues = []
    }
    if !validate(node: node) {
        issues.append("Invalid node structure")
        return
    }
    if node?.value == "error" {
        issues.append("Syntax error found")
    }
    for child in node?.children ?? [] {
        analyze(node: child, issues: &issues)
    }
}

func main() {
    let tree = Node(value: "start", children: [
        Node(value: "statement", children: [
            Node(value: "expression", children: [
                Node(value: "term", children: [
                    Node(value: "factor", children: [
                        Node(value: "number", value: "42")
                    ])
                ])
            ])
        ]),
        Node(value: "error")
    ])
    var issues: [String] = []
    analyze(node: tree, issues: &issues)
    for issue in issues {
        print(issue)
    }
}

main()