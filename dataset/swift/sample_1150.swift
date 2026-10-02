class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func traverse(_ node: Node) {
    if !node.children.isEmpty {
        for child in node.children {
            traverse(child)
        }
    }
    print(node.value)
}

func lint(_ node: Node) {
    if node.value == "invalid" {
        print("Linting error: Invalid value found.")
    }
    for child in node.children {
        lint(child)
    }
}

func construct_tree() -> Node {
    let root = Node(value: "root")
    let child1 = Node(value: "child1")
    let child2 = Node(value: "child2")
    let child3 = Node(value: "invalid")
    child1.children.append(Node(value: "subchild1"))
    child1.children.append(Node(value: "subchild2"))
    child2.children.append(Node(value: "subchild3"))
    child3.children.append(Node(value: "subchild4"))
    root.children.append(child1)
    root.children.append(child2)
    root.children.append(child3)
    return root
}

func main() {
    let tree = construct_tree()
    while true {
        traverse(tree)
        lint(tree)
    }
}

main()