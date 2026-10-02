import Foundation

class SequenceGenerator {
    var size: Int
    var sequence: [Int]

    init(size: Int) {
        self.size = size
        self.sequence = []
    }

    func generateFibonacci() {
        var a = 0
        var b = 1
        for _ in 0..<size {
            sequence.append(a)
            let temp = a
            a = b
            b = temp + b
        }
    }

    func generateArithmetic(diff: Int) {
        for i in 0..<size {
            sequence.append(diff * i)
        }
    }

    func generateGeometric(ratio: Int) {
        for i in 0..<size {
            sequence.append(Int(pow(Double(ratio), Double(i))))
        }
    }
}

class DataProcessor {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func calculateMean() -> Double {
        return Double(sequence.reduce(0, +)) / Double(sequence.count)
    }

    func calculateMedian() -> Double {
        let sortedSeq = sequence.sorted()
        let mid = sortedSeq.count / 2
        return sortedSeq.count % 2 == 0 ? Double(sortedSeq[mid - 1] + sortedSeq[mid]) / 2.0 : Double(sortedSeq[mid])
    }

    func calculateVariance() -> Double {
        let mean = calculateMean()
        return Double(sequence.reduce(0, { $0 + pow(Double($1 - Int(mean)), 2) })) / Double(sequence.count)
    }
}

class Optimizer {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func optimizeSupplyChain() -> [String: Double] {
        let mean = processor.calculateMean()
        let median = processor.calculateMedian()
        let variance = processor.calculateVariance()
        return ["mean": mean, "median": median, "variance": variance]
    }
}

func main() {
    let size = 10
    let diff = 2
    let ratio = 3
    let generator = SequenceGenerator(size: size)
    generator.generateFibonacci()
    let processor = DataProcessor(sequence: generator.sequence)
    let optimizer = Optimizer(processor: processor)
    let result = optimizer.optimizeSupplyChain()
    print(result)
}

main()