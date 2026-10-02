import Foundation

class SyntaxTree {
    var value: Any
    var children: [SyntaxTree]

    init(value: Any, children: [SyntaxTree] = []) {
        self.value = value
        self.children = children
    }

    func addChild(_ child: SyntaxTree) {
        children.append(child)
    }

    func traverse() -> AnySequence<Any> {
        var generator: AnyIterator<Any> = AnyIterator {
            return self.value as? Any
        }

        for child in self.children {
            generator = AnyIterator(AnySequence(child.traverse()).makeIterator()).merging(AnySequence(generator)) { $1 }
        }

        return AnySequence(generator)
    }
}

class Linter {
    var tree: SyntaxTree
    var errors: [Any] = []

    init(tree: SyntaxTree) {
        self.tree = tree
    }

    func check() {
        for node in tree.traverse() {
            if self.isInvalid(node) {
                errors.append(node)
            }
        }
    }

    func isInvalid(_ node: Any) -> Bool {
        if let number = node as? Int {
            return number < 0
        }
        return false
    }
}

class SequenceGenerator {
    var rules: [((Int) -> Int)]

    init(rules: [((Int) -> Int)]) {
        self.rules = rules
    }

    func generate(length: Int) -> [Int] {
        var sequence: [Int] = []
        for i in 0..<length {
            let value = self.applyRules(index: i)
            sequence.append(value)
        }
        return sequence
    }

    func applyRules(index: Int) -> Int {
        return index * index
    }
}

func main() {
    let root = SyntaxTree(value: 1)
    let child1 = SyntaxTree(value: -2)
    let child2 = SyntaxTree(value: 3)
    root.addChild(child1)
    root.addChild(child2)
    let linter = Linter(tree: root)
    linter.check()
    print("Errors:", linter.errors)
    let rules: [(Int) -> Int] = [{ $0 + 1 }, { $0 * 2 }]
    let generator = SequenceGenerator(rules: rules)
    let sequence = generator.generate(length: 10)
    print("Sequence:", sequence)
}

main()