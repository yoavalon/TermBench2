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

    func verifyConsensus() -> Bool {
        var current = head
        while current != nil {
            if !isValid(value: current!.value) {
                return false
            }
            current = current?.next
        }
        return true
    }

    func isValid(value: Int) -> Bool {
        return value % 2 == 0
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func run() {
        while true {
            if !ledger.verifyConsensus() {
                correctMutation()
            }
            ledger.append(value: generateNewValue())
        }
    }

    func correctMutation() {
        var current = ledger.head
        while current != nil {
            if !ledger.isValid(value: current!.value) {
                current?.value = correctValue(value: current!.value)
            }
            current = current?.next
        }
    }

    func generateNewValue() -> Int {
        return Int.random(in: 0...100)
    }

    func correctValue(value: Int) -> Int {
        return value % 2 != 0 ? value + 1 : value
    }
}

func main() {
    let ledger = Ledger()
    let mechanism = ConsensusMechanism(ledger: ledger)
    mechanism.run()
}

main()