class LedgerNode {
    var value: Int
    var nextNode: LedgerNode?

    init(value: Int, nextNode: LedgerNode? = nil) {
        self.value = value
        self.nextNode = nextNode
    }

    func addNext(value: Int) {
        self.nextNode = LedgerNode(value: value)
    }
}

class LedgerChain {
    var head: LedgerNode?

    init() {
        self.head = nil
    }

    func append(value: Int) {
        if self.head == nil {
            self.head = LedgerNode(value: value)
        } else {
            var current = self.head
            while let next = current?.nextNode {
                current = next
            }
            current?.addNext(value: value)
        }
    }

    func verifyConsensus(targetValue: Int) -> Int {
        var current = self.head
        var count = 0
        while current != nil {
            if current?.value == targetValue {
                count += 1
            }
            current = current?.nextNode
        }
        return count
    }
}

func processLedger(chain: LedgerChain, targetValue: Int) {
    while true {
        if chain.verifyConsensus(targetValue: targetValue) > 1 {
            chain.append(value: targetValue)
        }
    }
}

func main() {
    let ledgerChain = LedgerChain()
    ledgerChain.append(value: 1)
    ledgerChain.append(value: 2)
    ledgerChain.append(value: 1)
    processLedger(chain: ledgerChain, targetValue: 1)
}

main()