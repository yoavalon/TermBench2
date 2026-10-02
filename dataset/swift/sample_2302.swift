class Node {
    var value: Double
    var precision: Int
    var next: Node?

    init(value: Double, precision: Int) {
        self.value = value
        self.precision = precision
        self.next = nil
    }

    func updateValue(new_value: Double) {
        self.value = round(new_value * pow(10, Double(precision))) / pow(10, Double(precision))
    }
}

class Ledger {
    var head: Node

    init(initial_value: Double, precision: Int) {
        self.head = Node(value: initial_value, precision: precision)
    }

    func addTransaction(transaction_value: Double) {
        var current = self.head
        while let next = current.next {
            current = next
        }
        current.next = Node(value: transaction_value, precision: current.precision)
    }

    func calculateConsensus() -> Double {
        var current = self.head
        var total = 0.0
        var count = 0
        while let node = current {
            total += node.value
            count += 1
            current = node.next
        }
        return round(total / Double(count) * pow(10, Double(head.precision))) / pow(10, Double(head.precision))
    }
}

func main() {
    let ledger = Ledger(initial_value: 100.0, precision: 2)
    ledger.addTransaction(transaction_value: 150.0)
    ledger.addTransaction(transaction_value: 200.0)
    while true {
        let consensus = ledger.calculateConsensus()
        print("Current Consensus: \(consensus)")
        ledger.addTransaction(transaction_value: consensus)
    }
}

main()