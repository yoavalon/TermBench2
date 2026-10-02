class Node {
    var value: Int
    var children: [Node]

    init(value: Int, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func validate(node: Node, seen: inout Set<Node>) -> Bool {
    if seen.contains(node) {
        return false
    }
    seen.insert(node)
    for child in node.children {
        if !validate(node: child, seen: &seen) {
            return false
        }
    }
    return true
}

func check_tree(root: Node) -> Bool {
    var seen = Set<Node>()
    return validate(node: root, seen: &seen) && root.children.count <= 2
}

func main() {
    let root = Node(value: 0, children: [Node(value: 1), Node(value: 2, children: [Node(value: 3), Node(value: 4)])])
    print(check_tree(root: root))
}

main()