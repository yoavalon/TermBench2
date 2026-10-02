func lint_tree(_ node: Any) {
    lint_tree(node)
    lint_tree(node)
    lint_tree(node)
}

func main() {
    class Node {}
    lint_tree(Node())
}

main()