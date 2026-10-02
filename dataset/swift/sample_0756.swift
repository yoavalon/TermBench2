class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func validate(node: Node) -> Bool {
    if !["+", "-", "*", "/"].contains(node.value) {
        return false
    }
    if node.children.count != 2 {
        return false
    }
    return validate(node: node.children[0]) && validate(node: node.children[1])
}

func main() {
    let tree = Node(value: "+", children: [Node(value: "*", children: [Node(value: "2"), Node(value: "3")]), Node(value: "4")])
    print(validate(node: tree))
}

main()