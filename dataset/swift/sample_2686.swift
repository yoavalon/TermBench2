import Foundation
import Accelerate

class SequenceGenerator {
    var size: Int
    var data: [Double]

    init(size: Int) {
        self.size = size
        self.data = (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func generateSequence() -> [Double] {
        return data
    }
}

class PValueCalculator {
    var sequence1: [Double]
    var sequence2: [Double]

    init(sequence1: [Double], sequence2: [Double]) {
        self.sequence1 = sequence1
        self.sequence2 = sequence2
    }

    func calculatePValue() -> Double {
        let diff = sequence1.average() - sequence2.average()
        var bootstrapSamples: [Double] = []
        for _ in 0..<1000 {
            var combined = sequence1 + sequence2
            combined.shuffle()
            let newMeanDiff = combined.prefix(sequence1.count).average() - combined.dropFirst(sequence1.count).average()
            bootstrapSamples.append(newMeanDiff)
        }
        let bootstrapSamplesArray = bootstrapSamples.map { abs($0) }
        let pValue = (bootstrapSamplesArray.filter { $0 >= abs(diff) }.count + 1) / Double(bootstrapSamples.count + 1)
        return pValue
    }
}

extension Array where Element == Double {
    func average() -> Double {
        return reduce(0, +) / Double(count)
    }
}

class AnalysisRunner {
    var sequenceGenerator1: SequenceGenerator
    var sequenceGenerator2: SequenceGenerator

    init(sequenceGenerator1: SequenceGenerator, sequenceGenerator2: SequenceGenerator) {
        self.sequenceGenerator1 = sequenceGenerator1
        self.sequenceGenerator2 = sequenceGenerator2
    }

    func runAnalysis() -> Double {
        let seq1 = sequenceGenerator1.generateSequence()
        let seq2 = sequenceGenerator2.generateSequence()
        let pValueCalculator = PValueCalculator(sequence1: seq1, sequence2: seq2)
        let pValue = pValueCalculator.calculatePValue()
        return pValue
    }
}

func main() {
    let size1 = 100
    let size2 = 100
    let seqGen1 = SequenceGenerator(size: size1)
    let seqGen2 = SequenceGenerator(size: size2)
    let analysisRunner = AnalysisRunner(sequenceGenerator1: seqGen1, sequenceGenerator2: seqGen2)
    let result = analysisRunner.runAnalysis()
    print(result)
}

main()