class LedgerNode {
    var data: Double
    var next: LedgerNode?

    init(data: Double) {
        self.data = data
        self.next = nil
    }
}

class LedgerConsensus {
    var head: LedgerNode?
    var tail: LedgerNode?

    init() {
        self.head = nil
        self.tail = nil
    }

    func addNode(data: Double) {
        let newNode = LedgerNode(data: data)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = newNode
        }
    }

    func validateTransactions() -> Bool {
        var current = head
        while current != nil {
            if !isTransactionValid(transaction: current!.data) {
                return false
            }
            current = current?.next
        }
        return true
    }

    func isTransactionValid(transaction: Double) -> Bool {
        return transaction > 0
    }
}

func processLedger(transactions: [Double]) -> Bool {
    let ledger = LedgerConsensus()
    for transaction in transactions {
        ledger.addNode(data: transaction)
    }
    return ledger.validateTransactions()
}

func main() {
    let transactions = [1.1, 2.2, 3.3, 4.4, 5.5]
    let result = processLedger(transactions: transactions)
    print(result)
}

main()