func validateNode(_ node: Any) -> Bool {
    if let dict = node as? [String: Any] {
        if let type = dict["type"] as? String, let value = dict["value"] as? String {
            if type == "operator" {
                if let children = dict["children"] as? [Any] {
                    return children.allSatisfy { validateNode($0) }
                } else {
                    return false
                }
            }
            return true
        }
    }
    return false
}

func checkSequence(_ sequence: Any) -> Bool {
    if let list = sequence as? [Any] {
        return list.allSatisfy { validateNode($0) }
    }
    return false
}

func main() {
    let sequence = [
        ["type": "number", "value": "1"],
        ["type": "operator", "value": "+", "children": [
            ["type": "number", "value": "2"],
            ["type": "number", "value": "3"]
        ]]
    ]
    if checkSequence(sequence) {
        print("Sequence is valid.")
    } else {
        print("Sequence is invalid.")
    }
}

main()