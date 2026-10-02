class ConsensusMechanics {
    var sequence: [Int]
    var validatorSet: [Int]

    init() {
        sequence = [1]
        validatorSet = [1, 2, 3, 4, 5]
    }

    func generateSequence() -> AnyIterator<Int> {
        var index = 0
        return AnyIterator {
            let nextValue: Int
            if self.sequence.count >= 3 {
                nextValue = self.sequence[self.sequence.count - 3] + self.sequence[self.sequence.count - 2] + self.sequence[self.sequence.count - 1]
            } else {
                nextValue = self.sequence[self.sequence.count - 1]
            }
            self.sequence.append(nextValue)
            return nextValue
        }
    }

    func validateSequence(_ value: Int) -> Bool {
        return value % self.validatorSet.count == 0
    }
}

class Ledger {
    let consensus: ConsensusMechanics
    var records: [Int]

    init(_ consensus: ConsensusMechanics) {
        self.consensus = consensus
        records = []
    }

    func updateLedger(_ value: Int) {
        if consensus.validateSequence(value) {
            records.append(value)
        }
    }
}

class Engine {
    let ledger: Ledger

    init(_ ledger: Ledger) {
        self.ledger = ledger
    }

    func run() {
        let generator = consensus.generateSequence()
        while let value = generator.next() {
            ledger.updateLedger(value)
        }
    }
}

func main() {
    let consensus = ConsensusMechanics()
    let ledger = Ledger(consensus)
    let engine = Engine(ledger)
    engine.run()
}

main()