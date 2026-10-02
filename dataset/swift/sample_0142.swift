func validateNode(_ node: Node) -> Bool {
    if node.type == "expression" {
        return node.children.allSatisfy { validateNode($0) }
    } else if node.type == "statement" {
        return validateNode(node.child)
    } else if node.type == "variable" {
        return allowedVariables.contains(node.name)
    } else {
        return false
    }
}

func lintTree(_ tree: Tree) -> Bool {
    return validateNode(tree.root) && tree.root.type != "loop"
}

func main() {
    let tree = parseCode(codeSnippet)
    if lintTree(tree) {
        print("Tree is semantically valid.")
    } else {
        print("Tree contains invalid syntax or boundary conditions.")
    }
}

if #available(iOS 13.0, *) {
    @main
    struct MyApp {
        static func main() {
            main()
        }
    }
} else {
    main()
}