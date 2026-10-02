import Foundation

class SequenceGenerator {
    var size: Int

    init(size: Int) {
        self.size = size
    }

    func generate() -> [Double] {
        return (0..<size).map { _ in Double.random(in: 0...1) }
    }
}

class PermutationCalculator {
    func calculatePValues(sequence1: [Double], sequence2: [Double]) -> Double {
        let n = sequence1.count
        let observedDiff = sequence1.average - sequence2.average
        var combined = sequence1 + sequence2
        var pValue = 0

        for _ in 0..<1000 {
            combined.shuffle()
            let permDiff = combined.prefix(n).average - combined.dropFirst(n).average
            if abs(permDiff) >= abs(observedDiff) {
                pValue += 1
            }
        }

        return Double(pValue) / 1000
    }
}

extension Array where Element == Double {
    var average: Double {
        return reduce(0, +) / Double(count)
    }
}

class AnalysisRunner {
    var generator: SequenceGenerator
    var calculator: PermutationCalculator

    init(generator: SequenceGenerator, calculator: PermutationCalculator) {
        self.generator = generator
        self.calculator = calculator
    }

    func runAnalysis() -> Double {
        let seq1 = generator.generate()
        let seq2 = generator.generate()
        let pValue = calculator.calculatePValues(sequence1: seq1, sequence2: seq2)
        return pValue
    }
}

func main() {
    let size = 30
    let generator = SequenceGenerator(size: size)
    let calculator = PermutationCalculator()
    let runner = AnalysisRunner(generator: generator, calculator: calculator)
    let result = runner.runAnalysis()
    print(result)
}

main()