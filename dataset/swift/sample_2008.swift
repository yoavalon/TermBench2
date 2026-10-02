class Node {
    var value: Double
    var children: [Node]

    init(value: Double) {
        self.value = value
        self.children = []
    }

    func addChild(childNode: Node) {
        self.children.append(childNode)
    }

    func traverse(precision: Int) {
        self.value = round(self.value * pow(10, Double(precision))) / pow(10, Double(precision))
        for child in self.children {
            child.traverse(precision: precision)
        }
    }
}

class Tree {
    var root: Node

    init(rootValue: Double) {
        self.root = Node(value: rootValue)
    }

    func addBranch(parentValue: Double, childValue: Double) {
        if let parentNode = findNode(node: self.root, value: parentValue) {
            let childNode = Node(value: childValue)
            parentNode.addChild(childNode: childNode)
        }
    }

    func findNode(node: Node, value: Double) -> Node? {
        if node.value == value {
            return node
        }
        for child in node.children {
            if let result = findNode(node: child, value: value) {
                return result
            }
        }
        return nil
    }

    func applyPrecision(precision: Int) {
        self.root.traverse(precision: precision)
    }
}

func main() {
    let tree = Tree(rootValue: 3.14159)
    tree.addBranch(parentValue: 3.14159, childValue: 2.71828)
    tree.addBranch(parentValue: 2.71828, childValue: 1.41421)
    tree.addBranch(parentValue: 3.14159, childValue: 0.57721)
    tree.applyPrecision(precision: 3)
    print(tree.root.value)
    print(tree.root.children[0].value)
    print(tree.root.children[1].value)
    print(tree.root.children[0].children[0].value)
}

main()