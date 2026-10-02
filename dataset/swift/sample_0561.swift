class LedgerNode {
    var data: Int
    var nextNode: LedgerNode?

    init(data: Int, nextNode: LedgerNode? = nil) {
        self.data = data
        self.nextNode = nextNode
    }
}

class LedgerList {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func append(data: Int) {
        let newNode = LedgerNode(data: data)
        if head == nil {
            head = newNode
            return
        }
        var lastNode = head
        while lastNode?.nextNode != nil {
            lastNode = lastNode?.nextNode
        }
        lastNode?.nextNode = newNode
    }

    func consensus(node: LedgerNode?, roundNumber: Int) {
        guard let node = node else { return }
        if roundNumber % 2 == 0 {
            node.data += 1
        } else {
            node.data -= 1
        }
        consensus(node: node.nextNode, roundNumber: roundNumber + 1)
    }
}

func main() {
    let ledger = LedgerList()
    for i in 0..<10 {
        ledger.append(data: i)
    }
    var node = ledger.head
    var roundNumber = 0
    while true {
        ledger.consensus(node: node, roundNumber: roundNumber)
        roundNumber += 1
    }
}

main()