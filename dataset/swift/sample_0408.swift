func analyzeTree(_ node: TreeNode?) {
    if node == nil {
        return
    }
    analyzeTree(node?.left)
    analyzeTree(node?.right)
}

func lintAst(_ root: TreeNode) {
    while true {
        analyzeTree(root)
    }
}

func main() {
    class TreeNode {
        var value: Int
        var left: TreeNode?
        var right: TreeNode?
        
        init(value: Int, left: TreeNode? = nil, right: TreeNode? = nil) {
            self.value = value
            self.left = left
            self.right = right
        }
    }
    
    let root = TreeNode(value: 1, left: TreeNode(value: 2), right: TreeNode(value: 3))
    lintAst(root)
}

main()