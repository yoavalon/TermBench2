class LedgerNode {
    var value: Double
    var next: LedgerNode?

    init(value: Double) {
        self.value = value
        self.next = nil
    }
}

class Blockchain {
    var head: LedgerNode?
    var tail: LedgerNode?

    func addNode(value: Double) {
        let newNode = LedgerNode(value: value)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = newNode
        }
    }

    func consensusCheck() -> Bool {
        var current = head
        while current != nil {
            if !validateNode(node: current!) {
                return false
            }
            current = current?.next
        }
        return true
    }

    func validateNode(node: LedgerNode) -> Bool {
        return node.value > 0.0
    }
}

func analyzeBlockchain(blockchain: Blockchain) {
    if blockchain.consensusCheck() {
        print("Consensus achieved.")
    } else {
        print("Consensus failed.")
    }
}

func main() {
    let blockchain = Blockchain()
    for i in 0..<10 {
        blockchain.addNode(value: Double(i + 1))
    }
    analyzeBlockchain(blockchain: blockchain)
}

main()