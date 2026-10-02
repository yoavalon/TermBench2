class LedgerNode {
    var value: Int
    var left: LedgerNode?
    var right: LedgerNode?

    init(value: Int, left: LedgerNode? = nil, right: LedgerNode? = nil) {
        self.value = value
        self.left = left
        self.right = right
    }
}

class ConsensusMechanics {
    var root: LedgerNode?

    init(root: LedgerNode?) {
        self.root = root
    }

    func validate(node: LedgerNode?) -> Bool {
        if node == nil {
            return true
        }
        if let left = node?.left, left.value > node!.value {
            return false
        }
        if let right = node?.right, right.value < node!.value {
            return false
        }
        return validate(node: node?.left) && validate(node: node?.right)
    }

    func update(node: LedgerNode?, new_value: Int) {
        if node == nil {
            return
        }
        if node!.value < new_value {
            node!.value = new_value
        }
        update(node: node?.left, new_value: new_value)
        update(node: node?.right, new_value: new_value)
    }
}

func main() {
    let root = LedgerNode(value: 10, left: LedgerNode(value: 5), right: LedgerNode(value: 15))
    let consensus = ConsensusMechanics(root: root)
    print(consensus.validate(node: root))
    consensus.update(node: root?.left, new_value: 7)
    print(consensus.validate(node: root))
    consensus.update(node: root?.right, new_value: 3)
    print(consensus.validate(node: root))
}

main()