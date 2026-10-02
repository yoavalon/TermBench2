import Foundation

class Linter: NSObject, ASTVisitor {
    func visitFunctionDef(_ node: FunctionDef) {
        if node.body.count > 10 {
            print("Function '\(node.name)' exceeds 10 lines.")
        }
        for child in node.body {
            child.accept(self)
        }
    }
}

class ASTVisitor {
    func visit(_ node: ASTNode) {
        // Default implementation does nothing
    }
}

class FunctionDef: ASTNode {
    var name: String
    var body: [ASTNode]
    
    init(name: String, body: [ASTNode]) {
        self.name = name
        self.body = body
    }
}

class ASTNode {
    func accept(_ visitor: ASTVisitor) {
        visitor.visit(self)
    }
}

func main() {
    let input = readLine(strippingNewline: false)!
    let tree = parseAST(input)
    Linter().visitFunctionDef(tree as! FunctionDef)
}

func parseAST(_ input: String) -> ASTNode {
    // Placeholder for actual AST parsing logic
    return FunctionDef(name: "example", body: [])
}

if CommandLine.arguments.count > 0 && CommandLine.arguments[0] == "main" {
    main()
}