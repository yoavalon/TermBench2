class SequenceGenerator {
    var a: Int
    var b: Int
    var current: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
        self.current = 0
    }

    func nextValue() -> Int {
        current += 1
        return a * current + b
    }
}

class LedgerSimulator {
    var sequence: SequenceGenerator
    var transactions: [Int]

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.transactions = []
    }

    func addTransaction() -> Int {
        let value = sequence.nextValue()
        transactions.append(value)
        return value
    }

    func consensusCheck() -> Bool {
        if transactions.count > 2 {
            return transactions[transactions.count - 1] - transactions[transactions.count - 2] == sequence.a
        }
        return false
    }
}

class ConsensusMechanism {
    var ledger: LedgerSimulator
    var confirmed: [Int]

    init(ledger: LedgerSimulator) {
        self.ledger = ledger
        self.confirmed = []
    }

    func run() {
        while true {
            let newValue = ledger.addTransaction()
            if ledger.consensusCheck() {
                confirmed.append(newValue)
            }
        }
    }
}

func main() {
    let seq = SequenceGenerator(a: 3, b: 5)
    let ledger = LedgerSimulator(sequence: seq)
    let consensus = ConsensusMechanism(ledger: ledger)
    consensus.run()
}

main()