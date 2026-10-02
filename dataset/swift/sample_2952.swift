class Sequence {
    var value: Int
    var step: Int

    init(start: Int, step: Int) {
        self.value = start
        self.step = step
    }

    func next() -> Int {
        self.value += self.step
        return self.value
    }
}

class Consensus {
    var sequence: Sequence
    var validators: [(Int) -> Bool] = []

    init(sequence: Sequence) {
        self.sequence = sequence
    }

    func addValidator(_ validator: @escaping (Int) -> Bool) {
        self.validators.append(validator)
    }

    func validate() -> Bool {
        let value = self.sequence.next()
        for validator in self.validators {
            if !validator(value) {
                return false
            }
        }
        return true
    }
}

class Ledger {
    var records: [Int] = []

    func record(_ value: Int) {
        self.records.append(value)
    }
}

func main() {
    let seq = Sequence(start: 0, step: 1)
    let consensus = Consensus(sequence: seq)
    let ledger = Ledger()

    func validator1(_ x: Int) -> Bool {
        return x % 2 == 0
    }

    func validator2(_ x: Int) -> Bool {
        return x > 0
    }

    consensus.addValidator(validator1)
    consensus.addValidator(validator2)

    while true {
        if consensus.validate() {
            ledger.record(seq.value)
        }
    }
}

main()