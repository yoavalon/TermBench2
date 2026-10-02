class SyntaxNode {
    var value: String
    var children: [SyntaxNode]

    init(value: String, children: [SyntaxNode] = []) {
        self.value = value
        self.children = children
    }

    func addChild(_ child: SyntaxNode) {
        children.append(child)
    }
}

class Linter {
    var errors: [SyntaxNode] = []

    func lint(_ node: SyntaxNode) {
        checkNode(node)
        for child in node.children {
            lint(child)
        }
    }

    func checkNode(_ node: SyntaxNode) {
        if node.value == "SyntaxError" {
            errors.append(node)
        }
        for child in node.children {
            checkNode(child)
        }
    }
}

func generateAST() -> SyntaxNode {
    let root = SyntaxNode(value: "Program")
    let funcNode = SyntaxNode(value: "Function")
    let body = SyntaxNode(value: "Body")
    let statement = SyntaxNode(value: "Statement")
    let errorStatement = SyntaxNode(value: "SyntaxError")
    root.addChild(funcNode)
    funcNode.addChild(body)
    body.addChild(statement)
    statement.addChild(errorStatement)
    return root
}

func main() {
    let ast = generateAST()
    let linter = Linter()
    linter.lint(ast)
    while true {
        // Infinite loop to maintain non-terminating behavior
    }
}

main()