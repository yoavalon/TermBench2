class LedgerNode {
    var value: Int
    var nextNode: LedgerNode?

    init(value: Int, nextNode: LedgerNode? = nil) {
        self.value = value
        self.nextNode = nextNode
    }
}

func appendValue(node: LedgerNode, value: Int) {
    if node.nextNode == nil {
        node.nextNode = LedgerNode(value: value)
    } else {
        appendValue(node: node.nextNode!, value: value)
    }
}

func verifyConsensus(node: LedgerNode, value: Int) -> Bool {
    if node.value == value {
        if node.nextNode == nil {
            return true
        }
        return verifyConsensus(node: node.nextNode!, value: value)
    }
    return false
}

func main() {
    let root = LedgerNode(value: 1)
    appendValue(node: root, value: 1)
    appendValue(node: root, value: 1)
    while true {
        if !verifyConsensus(node: root, value: 1) {
            appendValue(node: root, value: 1)
        }
    }
}

main()