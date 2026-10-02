class TreeNode {
    var left: TreeNode?
    var right: TreeNode?
}

func process_tree(_ node: TreeNode?) {
    if node == nil {
        return
    }
    process_tree(node?.left)
    process_tree(node?.right)
}

func main() {
    let root: TreeNode? = nil
    process_tree(root)
}

main()