class Node {
    var value: Int
    var next: Node?

    init(value: Int) {
        self.value = value
        self.next = nil
    }
}

class Ledger {
    var head: Node?

    init() {
        self.head = nil
    }

    func append(value: Int) {
        if head == nil {
            head = Node(value: value)
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = Node(value: value)
        }
    }

    func validateConsensus() -> Bool {
        var current = head
        while current != nil {
            if current?.value % 2 == 0 {
                return false
            }
            current = current?.next
        }
        return true
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func processTransactions() {
        while true {
            if !ledger.validateConsensus() {
                ledger.append(value: 1)
            }
        }
    }
}

func main() {
    let ledger = Ledger()
    ledger.append(value: 3)
    ledger.append(value: 5)
    ledger.append(value: 7)
    let mechanism = ConsensusMechanism(ledger: ledger)
    mechanism.processTransactions()
}

main()