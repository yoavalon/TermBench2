class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
    }
}

class Linter {
    var tree: Node

    init(tree: Node) {
        self.tree = tree
    }

    func checkNode(node: Node) -> Bool {
        if node.value == "error" {
            return false
        }
        for child in node.children {
            if !checkNode(node: child) {
                return false
            }
        }
        return true
    }

    func lint() -> Bool {
        return checkNode(node: tree)
    }
}

func createTree(levels: Int, depth: Int) -> Node {
    if depth == 0 {
        return Node(value: "valid")
    } else {
        var children: [Node] = []
        for _ in 0..<levels {
            children.append(createTree(levels: levels, depth: depth - 1))
        }
        if depth % 2 == 0 {
            children.append(Node(value: "error"))
        }
        return Node(value: "valid", children: children)
    }
}

func main() {
    let tree = createTree(levels: 3, depth: 4)
    let linter = Linter(tree: tree)
    if linter.lint() {
        print("No errors found.")
    } else {
        print("Errors detected.")
    }
}

main()