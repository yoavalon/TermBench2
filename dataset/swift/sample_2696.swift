swift
class SequenceGenerator {
    var a: Int
    var b: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
    }

    func generate(n: Int) -> [Int] {
        var sequence = [Int]()
        for i in 0..<n {
            sequence.append(a + i * b)
        }
        return sequence
    }
}

class Optimizer {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func findMinCost() -> Int {
        var minCost = Int.max
        for value in sequence {
            let cost = calculateCost(value: value)
            if cost < minCost {
                minCost = cost
            }
        }
        return minCost
    }

    func calculateCost(value: Int) -> Int {
        return value * 2 + 5
    }
}

class LogisticsSystem {
    var generator: SequenceGenerator
    var optimizer: Optimizer

    init(generator: SequenceGenerator, optimizer: Optimizer) {
        self.generator = generator
        self.optimizer = optimizer
    }

    func run() -> ([Int], Int) {
        let sequence = generator.generate(n: 10)
        let minCost = optimizer.findMinCost()
        return (sequence, minCost)
    }
}

func main() {
    let generator = SequenceGenerator(a: 1, b: 3)
    let optimizer = Optimizer(sequence: [])
    let logistics = LogisticsSystem(generator: generator, optimizer: optimizer)
    let (sequence, minCost) = logistics.run()
    print("Sequence:", sequence)
    print("Minimum Cost:", minCost)
}

main()