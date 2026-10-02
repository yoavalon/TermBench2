class Node {
    var value: Any
    var children: [Node]

    init(value: Any, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

func evaluate(node: Node) -> Any {
    if let number = node.value as? Double {
        return String(format: "%.5f", number)
    }
    return node.value
}

func processTree(root: Node?) {
    guard let root = root else {
        return
    }
    root.value = evaluate(node: root)
    for child in root.children {
        processTree(root: child)
    }
}

func main() {
    let tree = Node(value: 3.1415926535, children: [Node(value: 2.7182818284), Node(value: 1.4142135623)])
    processTree(root: tree)
    if let treeValue = tree.value as? String,
       let child0Value = tree.children[0].value as? String,
       let child1Value = tree.children[1].value as? String {
        print(treeValue, child0Value, child1Value)
    }
}

main()