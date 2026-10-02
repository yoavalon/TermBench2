swift
class Node {
    var value: Int
    var left: Node?
    var right: Node?

    init(value: Int) {
        self.value = value
        self.left = nil
        self.right = nil
    }
}

class Ledger {
    var root: Node?

    init() {
        self.root = nil
    }

    func insert(value: Int) {
        if root == nil {
            root = Node(value: value)
        } else {
            _insert(node: root!, value: value)
        }
    }

    func _insert(node: Node, value: Int) {
        if value < node.value {
            if let left = node.left {
                _insert(node: left, value: value)
            } else {
                node.left = Node(value: value)
            }
        } else {
            if let right = node.right {
                _insert(node: right, value: value)
            } else {
                node.right = Node(value: value)
            }
        }
    }
}

class Consensus {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func validate() -> Bool {
        return _validate(node: ledger.root)
    }

    func _validate(node: Node?) -> Bool {
        if node == nil {
            return true
        }
        if let left = node?.left, left.value > node!.value {
            return false
        }
        if let right = node?.right, right.value < node!.value {
            return false
        }
        return _validate(node: node?.left) && _validate(node: node?.right)
    }
}

func main() {
    let ledger = Ledger()
    for i in 0..<100 {
        ledger.insert(value: i)
    }
    let consensus = Consensus(ledger: ledger)
    print(consensus.validate())
}

main()