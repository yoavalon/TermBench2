import Foundation

func validateNode(_ node: Any) throws {
    if let list = node as? [Any] {
        for child in list {
            try validateNode(child)
        }
    } else if let dict = node as? [String: Any] {
        for (key, value) in dict {
            try validateNode(key)
            try validateNode(value)
        }
    } else if !(node is Int || node is Double || node is String || node is Bool || node is NSNull) {
        throw NSError(domain: "Invalid node type", code: 0, userInfo: nil)
    }
}

func lintTree(_ tree: Any) throws -> String {
    try validateNode(tree)
    return "Tree validated"
}

func main() {
    let testTree: [Any] = [1, ["key": "value", "nested": [3, ["deep": 4]]], NSNull()]
    do {
        let result = try lintTree(testTree)
        print(result)
    } catch {
        print(error.localizedDescription)
    }
}

main()