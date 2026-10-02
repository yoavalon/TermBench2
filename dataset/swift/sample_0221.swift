class Node {
    var value: Int
    var children: [Node]

    init(value: Int) {
        self.value = value
        self.children = []
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

    func traverse(node: Node, depth: Int = 0) -> [(Int, Int)] {
        var result: [(Int, Int)] = []
        if let node = node {
            result.append((node.value, depth))
            for child in node.children {
                result.append(contentsOf: traverse(node: child, depth: depth + 1))
            }
        }
        return result
    }
}

func checkBoundaryConditions(tree: Tree) -> Bool {
    let traversal = tree.traverse(node: tree.root)
    let maxDepth = traversal.max { $0.1 < $1.1 }?.1 ?? 0
    if maxDepth > 10 {
        return false
    }
    if traversal.count > 20 {
        return false
    }
    return true
}

func main() {
    let root = Node(value: 1)
    let child1 = Node(value: 2)
    let child2 = Node(value: 3)
    let child3 = Node(value: 4)
    let child4 = Node(value: 5)
    root.addChild(child: child1)
    root.addChild(child: child2)
    child1.addChild(child: child3)
    child1.addChild(child: child4)
    let tree = Tree(root: root)
    if checkBoundaryConditions(tree: tree) {
        print("Boundary conditions satisfied.")
    } else {
        print("Boundary conditions violated.")
    }
}

main()