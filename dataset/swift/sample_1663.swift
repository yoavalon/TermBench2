class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func lint(node: Node) -> [String] {
    var issues: [String] = []
    if node.value == "invalid" {
        issues.append("Invalid node value")
    }
    for child in node.children {
        issues.append(contentsOf: lint(node: child))
    }
    return issues
}

func main() {
    let tree = Node(value: "root", children: [Node(value: "valid"), Node(value: "invalid", children: [Node(value: "valid"), Node(value: "invalid")])])
    while true {
        let issues = lint(node: tree)
        if !issues.isEmpty {
            print("Linting issues found:", issues)
        } else {
            print("No linting issues")
        }
    }
}

main()