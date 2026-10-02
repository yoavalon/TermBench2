class SequenceGenerator {
    var a: Int
    var b: Int
    var n: Int
    var current: Int

    init(a: Int, b: Int, n: Int) {
        self.a = a
        self.b = b
        self.n = n
        self.current = a
    }

    func generateNext() -> Int? {
        if current < n {
            current += b
            return current
        }
        return nil
    }
}

class LogisticsOptimizer {
    var sequence: SequenceGenerator
    var optimized: [Int] = []

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
    }

    func optimize() -> [Int] {
        while true {
            if let nextValue = sequence.generateNext() {
                optimized.append(nextValue)
            } else {
                break
            }
        }
        return optimized
    }
}

func main() {
    let a = 1
    let b = 2
    let n = 20
    let sequence = SequenceGenerator(a: a, b: b, n: n)
    let optimizer = LogisticsOptimizer(sequence: sequence)
    let result = optimizer.optimize()
    print(result)
}

main()