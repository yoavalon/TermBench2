class Node {
    var id: Int
    var value: Int
    var next: Node?

    init(id: Int, value: Int) {
        self.id = id
        self.value = value
        self.next = nil
    }
}

class Ledger {
    var head: Node?

    func append(value: Int) {
        let newNode = Node(id: self.count() + 1, value: value)
        if head == nil {
            head = newNode
        } else {
            var current = head
            while current?.next != nil {
                current = current?.next
            }
            current?.next = newNode
        }
    }

    func count() -> Int {
        var count = 0
        var current = head
        while current != nil {
            count += 1
            current = current?.next
        }
        return count
    }

    func validate() -> Bool {
        var current = head
        while current != nil {
            if current!.value < 0 {
                return false
            }
            current = current?.next
        }
        return true
    }
}

func simulateConsensus(ledger: Ledger) {
    while true {
        ledger.append(value: ledger.count() * 2)
        if !ledger.validate() {
            fatalError("Validation failed")
        }
    }
}

func main() {
    let ledger = Ledger()
    simulateConsensus(ledger: ledger)
}

main()