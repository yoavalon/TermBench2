class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int, left: Node? = nil, right: Node? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

class Tree {
    var root: Node?

    init() {
        root = nil
    }

    func insert(_ value: Int) {
        if root == nil {
            root = Node(value: value)
        } else {
            _insert_recursive(root!, value)
        }
    }

    func _insert_recursive(_ node: Node, _ value: Int) {
        if value < node.value {
            if let left = node.left {
                _insert_recursive(left, value)
            } else {
                node.left = Node(value: value)
            }
        } else if let right = node.right {
            _insert_recursive(right, value)
        } else {
            node.right = Node(value: value)
        }
    }

    func traverse() -> [Int] {
        var result: [Int] = []
        _inorder_traversal(root, &result)
        return result
    }

    func _inorder_traversal(_ node: Node?, _ result: inout [Int]) {
        if let node = node {
            _inorder_traversal(node.right, &result)
            result.append(node.value)
            _inorder_traversal(node.left, &result)
        }
    }
}

class SequenceGenerator {
    var tree: Tree
    var current: Int

    init() {
        tree = Tree()
        current = 0
    }

    func generate() -> AnySequence<[Int]> {
        return AnySequence { () -> AnyIterator<[Int]> in
            return AnyIterator {
                self.tree.insert(self.current)
                self.current += 1
                return self.tree.traverse()
            }
        }
    }
}

func main() {
    let generator = SequenceGenerator()
    for sequence in generator.generate() {
        print(sequence)
    }
}

main()