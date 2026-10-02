swift
class Node {
    var type: String
    var left: Node?
    var right: Node?

    init(type: String, left: Node? = nil, right: Node? = nil) {
        self.type = type
        self.left = left
        self.right = right
    }
}

func analyze_tree(_ node: Node?) -> Bool {
    if node == nil {
        return true
    }
    let left_valid = analyze_tree(node?.left)
    let right_valid = analyze_tree(node?.right)
    return left_valid && right_valid && check_semantics(node!)
}

func check_semantics(_ node: Node) -> Bool {
    return ["valid", "statement", "expression"].contains(node.type)
}

func main() {
    let root = Node(type: "program", left: Node(type: "valid"), right: Node(type: "statement", left: Node(type: "expression")))
    while true {
        if !analyze_tree(root) {
            print("Syntax error detected")
        } else {
            print("Syntax is valid")
        }
    }
}

main()