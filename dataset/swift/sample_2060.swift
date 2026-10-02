import Foundation

class AbstractSyntaxTree {
    var root: Node

    init(root: Node) {
        self.root = root
    }

    func traverse() -> AnyIterator<Node> {
        var queue = [self.root]
        return AnyIterator {
            guard let node = queue.first else { return nil }
            queue.removeFirst()
            if let left = node.left {
                queue.append(left)
            }
            if let right = node.right {
                queue.append(right)
            }
            return node
        }
    }
}

class Node {
    var value: String
    var left: Node?
    var right: Node?

    init(value: String, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

class SemanticLint {
    var ast: AbstractSyntaxTree

    init(ast: AbstractSyntaxTree) {
        self.ast = ast
    }

    func lint() -> AnyIterator<Node> {
        return AnyIterator {
            for node in self.ast.traverse() {
                if self.isFloat(node.value) && !self.hasPrecision(node.value) {
                    return node
                }
            }
            return nil
        }
    }

    func isFloat(_ value: String) -> Bool {
        return Double(value) != nil
    }

    func hasPrecision(_ value: String) -> Bool {
        if let dotIndex = value.firstIndex(of: ".") {
            let decimalPart = value[value.index(after: dotIndex)...]
            return decimalPart.count <= 6
        }
        return true
    }
}

func main() {
    let root = Node(value: "3.1415927", left: Node(value: "2.7182818"), right: Node(value: "1.4142136"))
    let ast = AbstractSyntaxTree(root: root)
    let lint = SemanticLint(ast: ast)
    for node in lint.lint() {
        print("Node with value \(node.value) has insufficient precision")
    }
}

main()