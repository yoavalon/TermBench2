class Node {
    var value: String
    var children: [Node]

    init(value: String, children: [Node]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(child: Node) {
        children.append(child)
    }
}

class ASTValidator {
    let maxDepth: Int

    init(maxDepth: Int) {
        self.maxDepth = maxDepth
    }

    func validate(node: Node, currentDepth: Int = 0) throws {
        if currentDepth > maxDepth {
            throw NSError(domain: "Depth exceeds maximum allowed", code: 1, userInfo: nil)
        }
        for child in node.children {
            try validate(node: child, currentDepth: currentDepth + 1)
        }
    }
}

class Program {
    let ast: Node

    init(ast: Node) {
        self.ast = ast
    }

    func run() {
        do {
            let validator = ASTValidator(maxDepth: 5)
            try validator.validate(node: ast)
        } catch {
            print(error.localizedDescription)
        }
    }
}

func main() {
    let root = Node(value: "root")
    let child1 = Node(value: "child1")
    let child2 = Node(value: "child2")
    let child3 = Node(value: "child3")
    let child4 = Node(value: "child4")
    let child5 = Node(value: "child5")
    let child6 = Node(value: "child6")
    root.addChild(child: child1)
    root.addChild(child: child2)
    child1.addChild(child: child3)
    child1.addChild(child: child4)
    child2.addChild(child: child5)
    child3.addChild(child: child6)
    let program = Program(ast: root)
    program.run()
}

main()