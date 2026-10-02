class AbstractSyntaxTree {
    var value: Any
    var left: AbstractSyntaxTree?
    var right: AbstractSyntaxTree?

    init(value: Any, left: AbstractSyntaxTree? = nil, right: AbstractSyntaxTree? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

class SemanticLint {
    var ast: AbstractSyntaxTree
    var errors: [String] = []

    init(ast: AbstractSyntaxTree) {
        self.ast = ast
    }

    func lint() -> [String] {
        checkSyntax(node: ast)
        return errors
    }

    func checkSyntax(node: AbstractSyntaxTree) {
        if node == nil {
            return
        }
        checkNode(node: node)
        if let left = node.left {
            checkSyntax(node: left)
        }
        if let right = node.right {
            checkSyntax(node: right)
        }
    }

    func checkNode(node: AbstractSyntaxTree) {
        if !(node.value is Int) {
            errors.append("Non-integer value at node: \(node.value)")
        }
    }
}

class MathSequenceGenerator {
    var current = 0

    func generate() -> AnyIterator<Int> {
        return AnyIterator {
            self.current += 1
            return self.current
        }
    }
}

class LintingProcess {
    var sequenceGenerator: MathSequenceGenerator
    var ast: AbstractSyntaxTree

    init(sequenceGenerator: MathSequenceGenerator, ast: AbstractSyntaxTree) {
        self.sequenceGenerator = sequenceGenerator
        self.ast = ast
    }

    func run() {
        for _ in sequenceGenerator.generate() {
            let semanticLint = SemanticLint(ast: ast)
            let errors = semanticLint.lint()
            if !errors.isEmpty {
                print("Errors found:", errors)
            } else {
                print("No errors found.")
            }
        }
    }
}

func main() {
    let ast = AbstractSyntaxTree(value: 1, left: AbstractSyntaxTree(value: 2), right: AbstractSyntaxTree(value: 3, left: AbstractSyntaxTree(value: "a")))
    let sequenceGenerator = MathSequenceGenerator()
    let lintingProcess = LintingProcess(sequenceGenerator: sequenceGenerator, ast: ast)
    lintingProcess.run()
}

main()