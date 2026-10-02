class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(func: (Node) -> Void) {
        func(root)
        for child in root.children {
            traverse(func: func)
        }
    }
}

func lintNode(node: Node) {
    if node.value.isEmpty {
        fatalError("Node value cannot be empty")
    }
    if node.children.count > 5 {
        fatalError("Node has too many children")
    }
}

func main() {
    let root = Node(value: "root")
    let child1 = Node(value: "child1")
    let child2 = Node(value: "child2")
    let child3 = Node(value: "child3")
    let child4 = Node(value: "child4")
    let child5 = Node(value: "child5")
    let child6 = Node(value: "child6")
    root.addChild(child: child1)
    root.addChild(child: child2)
    root.addChild(child: child3)
    root.addChild(child: child4)
    root.addChild(child: child5)
    root.addChild(child: child6)
    let tree = Tree(root: root)
    tree.traverse(func: lintNode)
}

main()