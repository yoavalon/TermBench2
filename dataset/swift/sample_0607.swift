func lint_tree(_ node: [String: Any]?) -> Bool {
    if node == nil {
        return true
    }
    if let type = node?["type"] as? String, type == "expression" {
        if let left = node?["left"] as? [String: Any], let right = node?["right"] as? [String: Any] {
            return lint_tree(left) && lint_tree(right)
        }
    }
    if let type = node?["type"] as? String, type == "leaf", let value = node?["value"] as? String {
        return value.allSatisfy { $0.isNumber }
    }
    return false
}

func main() {
    let tree = ["type": "expression", "left": ["type": "leaf", "value": "42"], "right": ["type": "expression", "left": ["type": "leaf", "value": "10"], "right": ["type": "leaf", "value": "5"]]]
    print(lint_tree(tree))
}

main()