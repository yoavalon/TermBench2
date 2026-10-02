import Foundation

class TemporalFrameSequence {

    var sequence: [Double]
    var threshold: Int

    init(sequence: [Double], threshold: Int) {
        self.sequence = sequence
        self.threshold = threshold
    }

    func calculatePrecision() -> [Int] {
        var precision: [Int] = []
        for frame in sequence {
            precision.append(frame.description.split(separator: ".").last?.count ?? 0)
        }
        return precision
    }

    func filterByThreshold(precision: [Int]) -> [Double] {
        var filteredSequence: [Double] = []
        for i in 0..<precision.count {
            if precision[i] > threshold {
                filteredSequence.append(sequence[i])
            }
        }
        return filteredSequence
    }
}

class PrecisionAnalyzer {

    var data: [Int]

    init(data: [Int]) {
        self.data = data
    }

    func analyze() -> Double {
        let totalPrecision = data.reduce(0, +)
        let averagePrecision = data.isEmpty ? 0 : Double(totalPrecision) / Double(data.count)
        return averagePrecision
    }
}

func main() {
    let sequence = [1.0, 2.0, 3.0, 4.0, 5.0]
    let threshold = 23
    let temporalFrame = TemporalFrameSequence(sequence: sequence, threshold: threshold)
    let precision = temporalFrame.calculatePrecision()
    let filteredSequence = temporalFrame.filterByThreshold(precision: precision)
    let analyzer = PrecisionAnalyzer(data: precision)
    let averagePrecision = analyzer.analyze()
    print(averagePrecision)
}

main()