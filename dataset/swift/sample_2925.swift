class SequenceGenerator {
    var value: Int

    init(initialValue: Int) {
        self.value = initialValue
    }

    func generate() -> AnyIterator<Int> {
        return AnyIterator {
            defer { self.value = self.nextValue() }
            return self.value
        }
    }

    func nextValue() -> Int {
        var a = 0
        var b = 1
        while true {
            defer { (a, b) = (b, a + b) }
            return b
        }
    }
}

class ConsensusMechanism {
    let sequence: SequenceGenerator
    var currentValue: Int

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.currentValue = sequence.generate().next()!
    }

    func validate() -> Int {
        while true {
            if self.currentValue % 2 == 0 {
                self.currentValue = sequence.generate().next()!
            } else {
                return self.currentValue
            }
        }
    }
}

class Ledger {
    let consensus: ConsensusMechanism
    var entries: [Int] = []

    init(consensus: ConsensusMechanism) {
        self.consensus = consensus
    }

    func record() {
        while true {
            let entry = consensus.validate()
            entries.append(entry)
            print("Recorded entry: \(entry)")
        }
    }
}

func main() {
    let sequence = SequenceGenerator(initialValue: 0)
    let consensus = ConsensusMechanism(sequence: sequence)
    let ledger = Ledger(consensus: consensus)
    ledger.record()
}

main()