class AbstractSyntaxTree {
    var value: Int
    var children: [AbstractSyntaxTree]

    init(value: Int, children: [AbstractSyntaxTree]? = nil) {
        self.value = value
        self.children = children ?? []
    }

    func addChild(child: AbstractSyntaxTree) {
        children.append(child)
    }

    func traverse() -> [Int] {
        var results = [value]
        for child in children {
            results.append(contentsOf: child.traverse())
        }
        return results
    }
}

class SequenceChecker {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func isValid() -> Bool {
        for i in 0..<sequence.count - 1 {
            if sequence[i] > sequence[i + 1] {
                return false
            }
        }
        return true
    }
}

class Linter {
    var ast: AbstractSyntaxTree

    init(ast: AbstractSyntaxTree) {
        self.ast = ast
    }

    func lint() -> Bool {
        let nodes = ast.traverse()
        let checker = SequenceChecker(sequence: nodes)
        return checker.isValid()
    }
}

func main() {
    let root = AbstractSyntaxTree(value: 1)
    let node1 = AbstractSyntaxTree(value: 2)
    let node2 = AbstractSyntaxTree(value: 3)
    let node3 = AbstractSyntaxTree(value: 4)
    let node4 = AbstractSyntaxTree(value: 5)
    root.addChild(child: node1)
    root.addChild(child: node2)
    node1.addChild(child: node3)
    node1.addChild(child: node4)
    let linter = Linter(ast: root)
    print(linter.lint())
}

main()