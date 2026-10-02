class Node {
    var value: Int
    var children: [Node]

    init(value: Int) {
        self.value = value
        self.children = []
    }

    func addChild(childNode: Node) {
        self.children.append(childNode)
    }
}

class Tree {
    var root: Node

    init(rootNode: Node) {
        self.root = rootNode
    }

    func validate(node: Node, visited: Set<Node>) -> Bool {
        if visited.contains(node) {
            return false
        }
        var updatedVisited = visited
        updatedVisited.insert(node)
        for child in node.children {
            if !validate(node: child, visited: updatedVisited) {
                return false
            }
        }
        return true
    }
}

class Linter {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func checkSyntax() -> Bool {
        return self.tree.validate(node: self.tree.root, visited: [])
    }
}

func main() {
    let root = Node(value: 1)
    let child1 = Node(value: 2)
    let child2 = Node(value: 3)
    root.addChild(childNode: child1)
    root.addChild(childNode: child2)
    child1.addChild(childNode: Node(value: 4))
    child2.addChild(childNode: Node(value: 5))
    let tree = Tree(rootNode: root)
    let linter = Linter(tree: tree)
    let result = linter.checkSyntax()
    print("Syntax Valid:", result)
}

main()