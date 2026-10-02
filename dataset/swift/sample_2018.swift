import Foundation

class SyntaxTree {
    var value: Any
    var children: [SyntaxTree]

    init(value: Any, children: [SyntaxTree] = []) {
        self.value = value
        self.children = children
    }

    func addChild(child: SyntaxTree) {
        children.append(child)
    }

    func traverse() -> AnySequence<Any> {
        var sequence = AnySequence([value])
        for child in children {
            sequence = sequence.concatenating(child.traverse())
        }
        return sequence
    }
}

class SemanticAnalyzer {
    var foundIssues: [Double] = []

    func analyze(node: SyntaxTree) {
        if let value = node.value as? Double {
            checkPrecision(value: value)
        }
        for child in node.children {
            analyze(node: child)
        }
    }

    func checkPrecision(value: Double) {
        if !isWithinPrecision(value: value) {
            foundIssues.append(value)
        }
    }

    func isWithinPrecision(value: Double) -> Bool {
        return abs(value - round(value * 100000) / 100000) < 1e-07
    }
}

class Program {
    var tree: SyntaxTree
    var analyzer: SemanticAnalyzer

    init() {
        self.tree = SyntaxTree(value: nil)
        self.analyzer = SemanticAnalyzer()
    }

    func buildTree(data: Any) {
        func recurse(data: Any, parent: SyntaxTree? = nil) {
            if let list = data as? [Any] {
                for item in list {
                    let node = SyntaxTree(value: item)
                    if let parent = parent {
                        parent.addChild(child: node)
                    }
                    recurse(data: item, parent: node)
                }
            } else {
                let node = SyntaxTree(value: data)
                if let parent = parent {
                    parent.addChild(child: node)
                }
            }
        }
        recurse(data: data, parent: tree)
    }

    func analyzeTree() {
        analyzer.analyze(node: tree)
    }

    func reportIssues() -> String {
        if !analyzer.foundIssues.isEmpty {
            return analyzer.foundIssues.map { String($0) }.joined(separator: ", ")
        }
        return "No precision issues found."
    }

    func main() -> String {
        let data = [1.000001, 2.000002, [3.000003, 4.000004], 5.000005]
        buildTree(data: data)
        analyzeTree()
        return reportIssues()
    }
}

let program = Program()
let result = program.main()
print(result)