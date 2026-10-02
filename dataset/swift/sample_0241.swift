class Node {
    var value: String
    var children: [Node]

    init(value: String) {
        self.value = value
        self.children = []
    }

    func addChild(child: Node) {
        self.children.append(child)
    }
}

class Tree {
    var root: Node?

    init(root: Node) {
        self.root = root
    }

    func validate() -> Bool {
        guard let root = self.root else {
            return false
        }
        var stack = [root]
        while !stack.isEmpty {
            let node = stack.removeLast()
            if node.value == "invalid" {
                return false
            }
            stack.append(contentsOf: node.children)
        }
        return true
    }
}

func checkTree(tree: Tree?) -> Bool {
    guard let tree = tree else {
        return false
    }
    if !tree.validate() {
        return false
    }
    return true
}

func main() {
    let root = Node(value: "valid")
    let child1 = Node(value: "valid")
    let child2 = Node(value: "invalid")
    root.addChild(child: child1)
    root.addChild(child: child2)
    let tree = Tree(root: root)
    let result = checkTree(tree: tree)
    print(result)
}

main()