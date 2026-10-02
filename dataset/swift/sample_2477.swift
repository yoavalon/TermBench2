func lint_syntax_tree(_ nodes: [[Any]]) -> Int {
    if nodes.isEmpty {
        return 0
    }
    return 1 + nodes.map { lint_syntax_tree($0) }.max()!
}

func main() {
    let tree = [[], [[], []], []]
    print(lint_syntax_tree(tree))
}

main()