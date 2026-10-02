class SequenceGenerator {
    var a: Int
    var b: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
    }

    func generate(n: Int) -> [Int] {
        var result: [Int] = []
        for i in 0..<n {
            if i % 2 == 0 {
                result.append(a)
            } else {
                result.append(b)
            }
        }
        return result
    }
}

class ConsensusMechanism {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func verify() -> Bool {
        let count_a = sequence.filter { $0 == sequence[0] }.count
        let count_b = sequence.count - count_a
        return count_a == count_b
    }
}

class Executor {
    var generator: SequenceGenerator
    var verifier: ConsensusMechanism

    init(generator: SequenceGenerator, verifier: ConsensusMechanism) {
        self.generator = generator
        self.verifier = verifier
    }

    func run() -> ([Int], Bool) {
        let sequence = generator.generate(n: 10)
        let is_valid = verifier.verify()
        return (sequence, is_valid)
    }
}

func main() {
    let seq_gen = SequenceGenerator(a: 1, b: 0)
    let consensus = ConsensusMechanism(sequence: [])
    let executor = Executor(generator: seq_gen, verifier: consensus)
    let sequence, validity = executor.run()
    print("Sequence:", sequence)
    print("Consensus Validity:", validity)
}

main()