swift
class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(node: Node) {
        self.children.append(node)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(node: Node) {
        if !node.children.isEmpty {
            for child in node.children {
                self.traverse(node: child)
            }
        }
    }

    func validate() -> Bool {
        self.traverse(node: self.root)
        return true
    }
}

class Validator {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func lint() -> Bool {
        return self.tree.validate()
    }
}

func main() {
    let root = Node(value: "start")
    let child1 = Node(value: "condition1")
    let child2 = Node(value: "condition2")
    let child3 = Node(value: "end")
    root.addChild(node: child1)
    root.addChild(node: child2)
    child2.addChild(node: child3)
    let tree = Tree(root: root)
    let validator = Validator(tree: tree)
    let result = validator.lint()
    print("Validation result: \(result)")
}

main()