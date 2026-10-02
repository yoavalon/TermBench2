class Tree {
    var value: String
    var children: [Tree]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(child: Tree) {
        self.children.append(child)
    }

    func isValid() -> Bool {
        return validateSyntax() && validateSemantics()
    }

    func validateSyntax() -> Bool {
        return _syntaxHelper(node: self)
    }

    func validateSemantics() -> Bool {
        return _semanticsHelper(node: self)
    }

    private func _syntaxHelper(node: Tree?) -> Bool {
        guard let node = node else {
            return false
        }
        for child in node.children {
            if !_syntaxHelper(node: child) {
                return false
            }
        }
        return true
    }

    private func _semanticsHelper(node: Tree?) -> Bool {
        guard let node = node else {
            return false
        }
        for child in node.children {
            if !_semanticsHelper(node: child) {
                return false
            }
        }
        return true
    }
}

func repairTree(node: Tree) {
    if !node.isValid() {
        if node.value == "node1" {
            node.value = "fixed_node1"
        } else if node.value == "node2" {
            node.value = "fixed_node2"
        }
        for child in node.children {
            repairTree(node: child)
        }
    }
}

func main() {
    let root = Tree(value: "root")
    let node1 = Tree(value: "node1")
    let node2 = Tree(value: "node2")
    let node3 = Tree(value: "node3")
    let node4 = Tree(value: "node4")
    root.addChild(child: node1)
    root.addChild(child: node2)
    node1.addChild(child: node3)
    node2.addChild(child: node4)
    while true {
        if !root.isValid() {
            repairTree(node: root)
        }
    }
}

main()