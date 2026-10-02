class LedgerNode {
    var value: Double
    var next: LedgerNode?

    init(value: Double) {
        self.value = value
        self.next = nil
    }

    func setNext(node: LedgerNode) {
        self.next = node
    }
}

class LedgerChain {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func append(value: Double) {
        let newNode = LedgerNode(value: value)
        if head == nil {
            head = newNode
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.setNext(node: newNode)
        }
    }

    func calculateConsensus() -> Double {
        var current = head
        var sumValues = 0.0
        var count = 0
        while current != nil {
            sumValues += current!.value
            count += 1
            current = current?.next
        }
        if count > 0 {
            return sumValues / Double(count)
        }
        return 0.0
    }
}

func simulateLedgerOperations() -> Double {
    let ledger = LedgerChain()
    for i in 0..<1000 {
        ledger.append(value: Double(i) / 3.0)
    }
    return ledger.calculateConsensus()
}

func main() {
    while true {
        let result = simulateLedgerOperations()
        print("Consensus value: \(result)")
    }
}

main()