func validate(_ node: Any) -> Bool {
    if node is String {
        return true
    } else if let list = node as? [Any], !list.isEmpty {
        return list.allSatisfy { validate($0) }
    } else {
        return false
    }
}

func analyze_tree(_ tree: Any) -> Bool {
    guard let list = tree as? [Any], !list.isEmpty else {
        return false
    }
    return validate(list[0]) && list.dropFirst().allSatisfy { analyze_tree($0) }
}

func main() {
    let tree1: [Any] = ["root", ["child1", "child2"], ["child3"]]
    let tree2: [Any] = ["root", ["child1", ["grandchild1", "grandchild2"]], "child2"]
    let tree3: [Any] = ["root", ["child1"], []]
    print(analyze_tree(tree1))
    print(analyze_tree(tree2))
    print(analyze_tree(tree3))
}

main()