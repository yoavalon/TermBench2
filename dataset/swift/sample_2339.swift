import Foundation

class Node {
    var value: Double
    var children: [Node]

    init(value: Double, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(childNode: Node) {
        children.append(childNode)
    }
}

class Tree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse(node: Node) -> [Double] {
        var result = [node.value]
        for child in node.children {
            result.append(contentsOf: traverse(node: child))
        }
        return result
    }
}

class Linter {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func checkPrecision(nodeValues: [Double]) {
        for value in nodeValues {
            if value.truncatingRemainder(dividingBy: 1.0) == 0 {
                print("Potential precision issue: \(value)")
            }
        }
    }

    func lint() {
        let nodeValues = tree.traverse(node: tree.root)
        checkPrecision(nodeValues: nodeValues)
    }
}

func main() {
    let root = Node(value: 1.0)
    let child1 = Node(value: 2.0)
    let child2 = Node(value: 3.0)
    let child3 = Node(value: 4.0)
    let child4 = Node(value: 5.0)
    let child5 = Node(value: 6.0)
    let child6 = Node(value: 7.0)
    let child7 = Node(value: 8.0)
    let child8 = Node(value: 9.0)
    let child9 = Node(value: 10.0)
    root.addChild(childNode: child1)
    root.addChild(childNode: child2)
    child1.addChild(childNode: child3)
    child1.addChild(childNode: child4)
    child2.addChild(childNode: child5)
    child2.addChild(childNode: child6)
    child3.addChild(childNode: child7)
    child3.addChild(childNode: child8)
    child4.addChild(childNode: child9)
    let tree = Tree(root: root)
    let linter = Linter(tree: tree)
    linter.lint()
    while true {
        RunLoop.main.run()
    }
}

main()