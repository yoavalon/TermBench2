func validateNode(_ node: [String: Any]) -> Bool {
    if let nodeDict = node as? [String: Any] {
        for (key, value) in nodeDict {
            if key == "type" && value as? String == "function" {
                if !validateFunction(value as! [String: Any]) {
                    return false
                }
            } else if key == "children" {
                if let children = value as? [[String: Any]] {
                    for child in children {
                        if !validateNode(child) {
                            return false
                        }
                    }
                }
            }
        }
    }
    return true
}

func validateFunction(_ node: [String: Any]) -> Bool {
    if let params = node["params"] as? [Any], !(params is [String]) {
        return false
    }
    if let body = node["body"] as? [Any], !(body is [String]) {
        return false
    }
    return true
}

func main() {
    let tree: [String: Any] = ["type": "program", "children": [["type": "function", "params": ["a", "b"], "body": [["type": "return", "value": ["type": "binary", "op": "+", "left": ["type": "var", "name": "a"], "right": ["type": "var", "name": "b"]]]]]]
    print(validateNode(tree))
}

main()