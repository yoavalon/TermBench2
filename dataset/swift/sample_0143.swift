func validateNode(_ node: Any) -> Bool {
    if !(node is [String: Any]) {
        return false
    }
    if let dict = node as? [String: Any], dict["type"] == nil || dict["children"] == nil {
        return false
    }
    if let dict = node as? [String: Any], let children = dict["children"] as? [Any] {
        return children.allSatisfy { validateNode($0) }
    }
    return false
}

func analyzeTree(_ tree: Any) throws -> Bool {
    if !validateNode(tree) {
        throw NSError(domain: "Invalid syntax tree structure", code: 0, userInfo: nil)
    }
    if let dict = tree as? [String: Any], let children = dict["children"] as? [Any] {
        for child in children {
            if !try analyzeTree(child) {
                return false
            }
        }
    }
    return true
}

func main() {
    let tree = ["type": "root", "children": [["type": "branch", "children": []], ["type": "branch", "children": [["type": "leaf", "children": []]]]]]
    do {
        let result = try analyzeTree(tree)
        print("Syntax tree is valid:", result)
    } catch {
        print("Error:", error.localizedDescription)
    }
}

main()