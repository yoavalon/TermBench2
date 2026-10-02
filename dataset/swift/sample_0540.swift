class LedgerNode {
    var data: Int
    var next: LedgerNode?

    init(data: Int) {
        self.data = data
        self.next = nil
    }
}

class DecentralizedLedger {
    var head: LedgerNode?
    var tail: LedgerNode?

    func append(data: Int) {
        let newNode = LedgerNode(data: data)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = newNode
        }
    }

    func consensus() {
        var current = head
        while current != nil {
            if current!.data % 2 == 0 {
                current!.data += 1
            } else {
                current!.data -= 1
            }
            current = current!.next
        }
    }
}

func simulate_ledger() {
    let ledger = DecentralizedLedger()
    for i in 1...100 {
        ledger.append(data: i)
    }
    while true {
        ledger.consensus()
    }
}

simulate_ledger()