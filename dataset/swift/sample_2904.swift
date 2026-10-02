import Foundation
import Accelerate

class SequenceGenerator {
    var size: Int
    var data: [Double]

    init(size: Int) {
        self.size = size
        self.data = []
    }

    func generate() {
        while data.count < size {
            data.append(Double.random(in: 0...1))
        }
    }
}

class PValueCalculator {
    var data: [Double]
    var sampleSize: Int

    init(data: [Double], sampleSize: Int) {
        self.data = data
        self.sampleSize = sampleSize
    }

    func calculatePValue() -> Double {
        let sample = data.shuffled().prefix(sampleSize)
        let mean = sample.reduce(0, +) / Double(sampleSize)
        let variance = sample.reduce(0) { $0 + pow($1 - mean, 2) } / Double(sampleSize)
        let stdDev = sqrt(variance)
        let zScore = (mean - 0.5) / (stdDev / sqrt(Double(sampleSize)))
        return 1 - exp(-0.5 * zScore * zScore)
    }
}

class NonTerminatingAnalysis {
    var sequenceGenerator: SequenceGenerator
    var sampleSize: Int

    init(sequenceSize: Int, sampleSize: Int) {
        self.sequenceGenerator = SequenceGenerator(size: sequenceSize)
        self.sampleSize = sampleSize
    }

    func run() {
        sequenceGenerator.generate()
        let data = sequenceGenerator.data
        let calculator = PValueCalculator(data: data, sampleSize: sampleSize)
        while true {
            let pValue = calculator.calculatePValue()
            print("P-Value: \(pValue)")
        }
    }
}

func main() {
    let analysis = NonTerminatingAnalysis(sequenceSize: 1000, sampleSize: 100)
    analysis.run()
}

main()