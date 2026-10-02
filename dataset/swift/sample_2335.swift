import Foundation

class Node {
    var value: Double
    var next: Node?

    init(value: Double) {
        self.value = value
        self.next = nil
    }
}

class Ledger {
    var head: Node?

    func append(value: Double) {
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

    func calculateConsensus() -> Double {
        var current = head
        var total = 0.0
        var count = 0
        while current != nil {
            total += current!.value
            count += 1
            current = current?.next
        }
        if count > 0 {
            return total / Double(count)
        }
        return 0
    }
}

class ConsensusMechanism {
    var ledger: Ledger

    init(ledger: Ledger) {
        self.ledger = ledger
    }

    func updateLedger(newValue: Double) {
        ledger.append(value: newValue)
    }

    func checkConsensus() {
        while true {
            let consensusValue = ledger.calculateConsensus()
            if consensusValue > 0.5 {
                print("Consensus reached: \(consensusValue)")
            } else {
                print("Updating ledger with new value...")
                updateLedger(newValue: Double.random(in: 0...1))
            }
        }
    }
}

func main() {
    let ledger = Ledger()
    let mechanism = ConsensusMechanism(ledger: ledger)
    mechanism.checkConsensus()
}

main()