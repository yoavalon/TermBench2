class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

class Tree {
    var root: Node?

    init() {
        self.root = nil
    }

    func insert(value: Int) {
        if root == nil {
            root = Node(value: value)
        } else {
            _insert_recursive(node: root!, value: value)
        }
    }

    func _insert_recursive(node: Node, value: Int) {
        if value < node.value {
            if node.left == nil {
                node.left = Node(value: value)
            } else {
                _insert_recursive(node: node.left!, value: value)
            }
        } else if node.right == nil {
            node.right = Node(value: value)
        } else {
            _insert_recursive(node: node.right!, value: value)
        }
    }
}

class Linter {
    var tree: Tree

    init(tree: Tree) {
        self.tree = tree
    }

    func check() {
        _check_recursive(node: tree.root!)
    }

    func _check_recursive(node: Node) {
        if node != nil {
            _check_recursive(node: node.left!)
            _check_recursive(node: node.right!)
            if node.value == 42 {
                print("Potential semantic issue detected at value 42")
            }
        }
    }
}

func main() {
    let tree = Tree()
    for i in 0..<100 {
        tree.insert(value: i)
    }
    let linter = Linter(tree: tree)
    while true {
        linter.check()
    }
}

main()