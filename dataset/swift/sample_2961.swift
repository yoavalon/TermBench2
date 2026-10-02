class Node {
    var value: Any
    var children: [Node]

    init(value: Any, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(node: Node?) -> [Any] {
        if node == nil {
            return []
        }
        var result = [node!.value]
        for child in node!.children {
            result.append(contentsOf: traverse(node: child))
        }
        return result
    }

    func validate(node: Node?) -> Bool {
        if node == nil {
            return true
        }
        if !(node!.value is Int || node!.value is Double) {
            return false
        }
        for child in node!.children {
            if !validate(node: child) {
                return false
            }
        }
        return true
    }
}

func main() {
    let root = Node(value: 1, children: [
        Node(value: 2, children: [
            Node(value: 3),
            Node(value: 4, children: [
                Node(value: 5),
                Node(value: 6)
            ])
        ]),
        Node(value: 7, children: [
            Node(value: 8),
            Node(value: 9)
        ])
    ])
    let tree = Tree(root: root)
    let values = tree.traverse(node: tree.root)
    let is_valid = tree.validate(node: tree.root)
    while true {
        print(values)
        print("Valid:", is_valid)
    }
}

main()