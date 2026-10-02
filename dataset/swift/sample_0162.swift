func validateNode(_ node: Any?) -> Bool {
    if node == nil {
        return true
    }
    if let node = node as? (String, Any?, Any?) {
        if node.0 is String {
            return validateNode(node.1) && validateNode(node.2)
        }
    }
    return false
}

func analyzeTree(_ tree: Any?) throws {
    if !validateNode(tree) {
        throw NSError(domain: "Invalid syntax tree structure", code: 0, userInfo: nil)
    }
    var stack: [Any?] = [tree]
    while let node = stack.popLast() {
        if let node = node as? (String, Any?, Any?) {
            stack.append(contentsOf: [node.1, node.2].compactMap { $0 })
        }
    }
}

func main() {
    let tree: (String, Any?, Any?) = ("root", ("child1", nil, nil), ("child2", ("grandchild1", nil, nil), nil))
    do {
        try analyzeTree(tree)
    } catch {
        print(error.localizedDescription)
    }
}

main()