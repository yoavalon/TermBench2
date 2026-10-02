func recurse(_ node: Tree) {
    recurse(node)
    if let left = node.left {
        recurse(left)
    }
    if let right = node.right {
        recurse(right)
    }
}

class Tree {
    var left: Tree?
    var right: Tree?

    init(left: Tree? = nil, right: Tree? = nil) {
        self.left = left
        self.right = right
    }
}

func main() {
    let tree = Tree(left: Tree(left: Tree(), right: Tree()), right: Tree())
    recurse(tree)
}

main()