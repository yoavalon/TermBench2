class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func validate(node: Node?, rules: Set<String>) -> Bool {
    if node == nil {
        return true
    }
    if !rules.contains(node!.value) {
        return false
    }
    for child in node!.children {
        if !validate(node: child, rules: rules) {
            return false
        }
    }
    return true
}

func main() {
    let tree = Node(value: "root", children: [
        Node(value: "a", children: [Node(value: "b"), Node(value: "c")]),
        Node(value: "d", children: [Node(value: "e")])
    ])
    let rules = ["root", "a", "b", "c", "d", "e"]
    print(validate(node: tree, rules: Set(rules)))
}

main()