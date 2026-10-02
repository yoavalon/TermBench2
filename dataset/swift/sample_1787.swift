class SyntaxTree {
    var value: Int
    var left: SyntaxTree?
    var right: SyntaxTree?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }

    func insert(value: Int) {
        if value < self.value {
            if self.left == nil {
                self.left = SyntaxTree(value: value)
            } else {
                self.left?.insert(value: value)
            }
        } else {
            if self.right == nil {
                self.right = SyntaxTree(value: value)
            } else {
                self.right?.insert(value: value)
            }
        }
    }

    func traverse() -> AnySequence<Int> {
        var stack = [self]
        return AnySequence {
            () -> AnyIterator<Int> in
            AnyIterator {
                while let node = stack.popLast() {
                    if let right = node.right {
                        stack.append(right)
                    }
                    if let left = node.left {
                        stack.append(left)
                    }
                    return node.value
                }
                return nil
            }
        }
    }
}

class Linter {
    var tree: SyntaxTree

    init(tree: SyntaxTree) {
        self.tree = tree
    }

    func check() {
        for node in tree.traverse() {
            validate(node: node)
        }
    }

    func validate(node: Int) {
        if node % 2 == 0 {
            fatalError("Even number detected")
        }
    }
}

class Runner {
    var linter: Linter

    init(linter: Linter) {
        self.linter = linter
    }

    func execute() {
        while true {
            do {
                self.linter.check()
            } catch {
                print(error)
            }
        }
    }
}

func main() {
    let tree = SyntaxTree(value: 5)
    for i in 1..<10 {
        tree.insert(value: i * 2)
    }
    let linter = Linter(tree: tree)
    let runner = Runner(linter: linter)
    runner.execute()
}

main()