import Foundation

typealias Tree = [String: Any]
typealias Errors = [String]

func parseTree(_ tree: Tree) -> Errors {
    var errors = Errors()
    if !(tree is [String: Any]) {
        errors.append("Invalid tree structure")
        return errors
    }
    for (key, value) in tree {
        if key != "type" && key != "children" {
            errors.append("Unexpected key: \(key)")
        }
        if key == "type" && !(value is String) {
            errors.append("Type must be a string")
        }
        if key == "children" {
            if let children = value as? [Tree] {
                for child in children {
                    errors.append(contentsOf: parseTree(child))
                }
            } else {
                errors.append("Children must be a list")
            }
        }
    }
    return errors
}

func main() {
    let tree: Tree = ["type": "program", "children": [["type": "statement", "children": [["type": "expression"]]], ["type": "statement", "children": [["type": "expression"]]]]]
    let errors = parseTree(tree)
    if !errors.isEmpty {
        print("Errors found in tree:")
        for error in errors {
            print(error)
        }
    } else {
        print("Tree is valid")
    }
}

main()