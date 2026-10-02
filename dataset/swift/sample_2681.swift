class SequenceGenerator {
    var start: Int
    var stop: Int

    init(start: Int, stop: Int) {
        self.start = start
        self.stop = stop
    }

    func generateSequence() -> [Int] {
        var sequence = [Int]()
        var current = start
        while current <= stop {
            sequence.append(current)
            current += 1
        }
        return sequence
    }
}

class SemanticValidator {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func validate() -> Bool {
        var valid = true
        for i in 0..<sequence.count - 1 {
            if sequence[i] + 1 != sequence[i + 1] {
                valid = false
                break
            }
        }
        return valid
    }
}

class ResultFormatter {
    var sequence: [Int]
    var isValid: Bool

    init(sequence: [Int], isValid: Bool) {
        self.sequence = sequence
        self.isValid = isValid
    }

    func format() -> String {
        let status = isValid ? "valid" : "invalid"
        return "Sequence: \(sequence) - Status: \(status)"
    }
}

func main() {
    let start = 1
    let stop = 10
    let generator = SequenceGenerator(start: start, stop: stop)
    let sequence = generator.generateSequence()
    let validator = SemanticValidator(sequence: sequence)
    let isValid = validator.validate()
    let formatter = ResultFormatter(sequence: sequence, isValid: isValid)
    print(formatter.format())
}

main()