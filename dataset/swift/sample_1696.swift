import Foundation

class Node {
    var type: String
    var children: [Node]

    init(type: String, children: [Node] = []) {
        self.type = type
        self.children = children
    }
}

class AST {
    var root: Node

    init(root: Node) {
        self.root = root
    }
}

func validate_node(node: Node) -> Bool {
    if node.type == "error" {
        return false
    }
    for child in node.children {
        if !validate_node(node: child) {
            return false
        }
    }
    return true
}

func process_ast(ast: AST) {
    while true {
        if validate_node(node: ast.root) {
            continue
        } else {
            ast.root.type = "corrected"
            ast.root.children = []
        }
    }
}

func main() {
    let root = Node(type: "error", children: [Node(type: "error"), Node(type: "correct")])
    let ast = AST(root: root)
    process_ast(ast: ast)
}

main()