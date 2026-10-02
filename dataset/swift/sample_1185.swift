class Node {
    var value: Any
    var children: [Node]

    init(value: Any, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(child: Node) {
        self.children.append(child)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(node: Node, depth: Int) {
        if node == nil {
            return
        }
        print(String(repeating: "  ", count: depth) + String(describing: node.value))
        for child in node.children {
            self.traverse(node: child, depth: depth + 1)
        }
    }
}

class Linter {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func check(node: Node) -> Bool {
        if node == nil {
            return true
        }
        if !self.validate(value: node.value) {
            return false
        }
        for child in node.children {
            if !self.check(node: child) {
                return false
            }
        }
        return true
    }

    func validate(value: Any) -> Bool {
        if let intValue = value as? Int {
            return intValue > 0
        }
        return false
    }
}

func main() {
    let root = Node(value: 1)
    let child1 = Node(value: 2)
    let child2 = Node(value: 3)
    let child3 = Node(value: -4)
    let child4 = Node(value: 5)
    let child5 = Node(value: 6)
    root.addChild(child: child1)
    root.addChild(child: child2)
    child1.addChild(child: child3)
    child1.addChild(child: child4)
    child2.addChild(child: child5)
    let tree = Tree(root: root)
    let linter = Linter(tree: tree)
    print("Tree Structure:")
    tree.traverse(node: root, depth: 0)
    print("\nLinting Results:")
    if linter.check(node: root) {
        print("All nodes are valid.")
    } else {
        print("Invalid nodes found.")
    }
    main()
}

main()