class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

class Tree {
    var root: Node?

    init(root: Node?) {
        self.root = root
    }
}

func check_tree(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    if node!.value < 0 {
        return false
    }
    return check_tree(node!.left) && check_tree(node!.right)
}

func validate_syntax(_ tree: Tree) -> Bool {
    if tree.root == nil {
        return true
    }
    return check_tree(tree.root)
}

func main() {
    let tree = Tree(root: Node(value: 1, left: Node(value: 2), right: Node(value: 3, left: Node(value: -4))))
    print(validate_syntax(tree))
}

main()