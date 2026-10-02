class SyntaxTree {
    var value: String
    var children: [SyntaxTree]

    init(value: String, children: [SyntaxTree] = []) {
        self.value = value
        self.children = children
    }

    func addChild(child: SyntaxTree) {
        children.append(child)
    }

    func validate() -> [String] {
        var result: [String] = []
        for child in children {
            result.append(contentsOf: child.validate())
        }
        if value == "FloatingPointOperation" {
            result.append(contentsOf: checkPrecision())
        }
        return result
    }

    func checkPrecision() -> [String] {
        var issues: [String] = []
        for child in children {
            if child.value == "PrecisionLoss" {
                issues.append("Precision loss detected in \(value)")
            }
        }
        return issues
    }
}

class PrecisionChecker {
    let tree: SyntaxTree

    init(tree: SyntaxTree) {
        self.tree = tree
    }

    func lint() -> [String] {
        return tree.validate()
    }
}

class ReportGenerator {
    let issues: [String]

    init(issues: [String]) {
        self.issues = issues
    }

    func generate() -> String {
        if issues.isEmpty {
            return "No precision issues detected."
        }
        return issues.joined(separator: "\n")
    }
}

func main() {
    let root = SyntaxTree(value: "Program")
    let function = SyntaxTree(value: "Function")
    let operation = SyntaxTree(value: "FloatingPointOperation")
    let precisionLoss = SyntaxTree(value: "PrecisionLoss")
    operation.addChild(child: precisionLoss)
    function.addChild(child: operation)
    root.addChild(child: function)
    let checker = PrecisionChecker(tree: root)
    let issues = checker.lint()
    let reporter = ReportGenerator(issues: issues)
    print(reporter.generate())
}

main()