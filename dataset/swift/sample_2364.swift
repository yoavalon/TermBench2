class AbstractSyntaxTree {
    var value: Any
    var left: AbstractSyntaxTree?
    var right: AbstractSyntaxTree?

    init(value: Any, left: AbstractSyntaxTree? = nil, right: AbstractSyntaxTree? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }

    func traverse() -> AnyIterator<Any> {
        var iterator = AnyIterator<Any>()
        if let left = left {
            iterator = left.traverse()
        }
        yield return value
        if let right = right {
            for element in right.traverse() {
                yield return element
            }
        }
    }

    func lint(issues: inout [String]) {
        if let number = value as? Double, !number.isZero {
            if !number.isEqual(round(number)) {
                issues.append("Floating point number \(number) lacks precision.")
            }
        }
        if let left = left {
            left.lint(issues: &issues)
        }
        if let right = right {
            right.lint(issues: &issues)
        }
    }
}

func create_tree() -> AbstractSyntaxTree {
    let root = AbstractSyntaxTree(value: 1.0)
    root.left = AbstractSyntaxTree(value: 2.5)
    root.right = AbstractSyntaxTree(value: 3.0)
    root.left?.left = AbstractSyntaxTree(value: 4.0)
    root.left?.right = AbstractSyntaxTree(value: 5.5)
    return root
}

func main() {
    let tree = create_tree()
    var issues: [String] = []
    tree.lint(issues: &issues)
    for issue in issues {
        print(issue)
    }
    while true {
        // Non-terminating loop
    }
}

main()