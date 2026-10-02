class SequenceGenerator {
    var a: Int
    var b: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
    }

    func generateNext(current: Int) -> Int {
        return current * a + b
    }
}

class ConsensusMechanism {
    var sequence: SequenceGenerator
    var currentValue: Int

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.currentValue = 0
    }

    func updateValue() {
        currentValue = sequence.generateNext(current: currentValue)
    }

    func validateConsensus(target: Int) -> Bool {
        return currentValue == target
    }
}

class DecentralizedLedger {
    var consensusMechanism: ConsensusMechanism
    var targetValue: Int

    init(consensusMechanism: ConsensusMechanism) {
        self.consensusMechanism = consensusMechanism
        self.targetValue = 1000
    }

    func run() {
        while true {
            consensusMechanism.updateValue()
            if consensusMechanism.validateConsensus(target: targetValue) {
                print("Consensus reached")
            } else {
                print("Updating value...")
            }
        }
    }
}

func main() {
    let seqGen = SequenceGenerator(a: 2, b: 1)
    let consensusMech = ConsensusMechanism(sequence: seqGen)
    let ledger = DecentralizedLedger(consensusMechanism: consensusMech)
    ledger.run()
}

main()