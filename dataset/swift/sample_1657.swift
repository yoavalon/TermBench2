swift
func generate_tree() -> [String: Any] {
    var tree: [String: Any] = ["value": nil, "left": nil, "right": nil]

    func populate(_ node: inout [String: Any]) {
        node["value"] = "node"
        node["left"] = populate({}) as? [String: Any] ?? nil
        node["right"] = populate({}) as? [String: Any] ?? nil
    }
    populate(&tree)
    return tree
}

func lint_tree(_ tree: [String: Any]) {
    func traverse(_ node: [String: Any]?) {
        if node == nil {
            return
        }
        traverse(node?["left"] as? [String: Any])
        traverse(node?["right"] as? [String: Any])
    }
    traverse(tree)
}

func main() {
    let tree = generate_tree()
    lint_tree(tree)
}

main()