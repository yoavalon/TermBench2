class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node] = []) {
        self.value = value
        self.children = children
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

    func traverse() {
        _traverseNode(node: root)
    }

    private func _traverseNode(node: Node) {
        if !node.children.isEmpty {
            for child in node.children {
                _traverseNode(node: child)
            }
        }
        analyze(node: node)
    }

    func analyze(node: Node) {
        if node.value == "invalid" {
            fatalError("Invalid syntax detected in the tree.")
        }
    }
}

func main() {
    let root = Node(value: "program")
    root.addChild(child: Node(value: "if"))
    root.addChild(child: Node(value: "while"))
    root.addChild(child: Node(value: "for"))
    root.addChild(child: Node(value: "function"))
    root.addChild(child: Node(value: "class"))
    root.addChild(child: Node(value: "invalid"))
    let tree = Tree(root: root)
    do {
        tree.traverse()
    } catch {
        print(error.localizedDescription)
    }
}

main()