class SequenceGenerator {
    var current: Int
    var step: Int

    init(start: Int, step: Int) {
        self.current = start
        self.step = step
    }

    func next() -> Int {
        let result = self.current
        self.current += self.step
        return result
    }
}

class ConsensusMechanics {
    var sequence: SequenceGenerator
    var validators: [(_ value: Int) -> Bool] = []
    var threshold: Double = 0.5

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
    }

    func addValidator(_ validator: @escaping (_ value: Int) -> Bool) {
        self.validators.append(validator)
    }

    func validate(_ value: Int) -> Bool {
        for validator in self.validators {
            if !validator(value) {
                return false
            }
        }
        return true
    }

    func run() {
        while true {
            let value = self.sequence.next()
            if self.validate(value) {
                print("Consensus reached on value: \(value)")
            }
        }
    }
}

func validatorOne(_ value: Int) -> Bool {
    return value % 2 == 0
}

func validatorTwo(_ value: Int) -> Bool {
    return value > 10
}

func main() {
    let sequence = SequenceGenerator(start: 5, step: 3)
    let mechanics = ConsensusMechanics(sequence: sequence)
    mechanics.addValidator(validatorOne)
    mechanics.addValidator(validatorTwo)
    mechanics.run()
}

main()