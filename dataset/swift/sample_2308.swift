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
    var tail: Node?

    init() {
        self.head = nil
        self.tail = nil
    }

    func append(value: Int) {
        let newNode = Node(value: value)
        if head == nil {
            head = newNode
            tail = newNode
        } else {
            tail?.next = newNode
            tail = newNode
        }
    }

    func calculateConsensus() -> Double {
        var current = head
        var total = 0
        var count = 0
        while current != nil {
            total += current!.value
            count += 1
            current = current?.next
        }
        return count != 0 ? Double(total) / Double(count) : 0
    }
}

class ConsensusMechanics {
    var ledger: Ledger

    init() {
        self.ledger = Ledger()
    }

    func updateLedger(value: Int) {
        ledger.append(value: value)
    }

    func runConsensus() {
        while true {
            let consensusValue = ledger.calculateConsensus()
            updateLedger(value: Int(consensusValue))
        }
    }
}

func main() {
    let mechanics = ConsensusMechanics()
    for i in 0..<10 {
        mechanics.updateLedger(value: i)
    }
    mechanics.runConsensus()
}

main()