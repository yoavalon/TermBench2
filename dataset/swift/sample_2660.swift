class SequenceGenerator {
    var length: Int
    var sequence: [Int]

    init(length: Int) {
        self.length = length
        self.sequence = []
    }

    func generateSequence() -> [Int] {
        for i in 0..<length {
            sequence.append(calculateValue(index: i))
        }
        return sequence
    }

    func calculateValue(index: Int) -> Int {
        if index % 2 == 0 {
            return index * index
        } else {
            return Int(pow(Double(2), Double(index)))
        }
    }
}

class ConsensusMechanic {
    var sequence: [Int]
    var consolidated: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
        self.consolidated = []
    }

    func applyConsensus() -> [Int] {
        for value in sequence {
            consolidated.append(validateValue(value: value))
        }
        return consolidated
    }

    func validateValue(value: Int) -> Int {
        if value > 10 {
            return value - 5
        } else {
            return value * 2
        }
    }
}

func main() {
    let length = 20
    let generator = SequenceGenerator(length: length)
    let sequence = generator.generateSequence()
    let mechanic = ConsensusMechanic(sequence: sequence)
    let result = mechanic.applyConsensus()
    print(result)
}

main()