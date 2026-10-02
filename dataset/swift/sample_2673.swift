import Foundation

class SequenceGenerator {
    var length: Int
    var data: [Double]

    init(length: Int) {
        self.length = length
        self.data = [Double](repeating: 0.0, count: length)
    }

    func generateFibonacci() {
        if length > 0 {
            data[0] = 0
        }
        if length > 1 {
            data[1] = 1
        }
        for i in 2..<length {
            data[i] = data[i - 1] + data[i - 2]
        }
    }

    func generateHarmonic() {
        for i in 0..<length {
            data[i] = 1.0 / Double(i + 1)
        }
    }

    func getSequence() -> [Double] {
        return data
    }
}

func processSequence(seq: [Double]) -> [Double] {
    return seq.map { $0 > 0.5 ? $0 : 0 }
}

func analyzeSequence(seq: [Double]) -> (Double, Double, Double) {
    let meanValue = seq.reduce(0, +) / Double(seq.count)
    let maxValue = seq.max() ?? 0
    let minValue = seq.min() ?? 0
    return (meanValue, maxValue, minValue)
}

func main() {
    let seqGen = SequenceGenerator(length: 10)
    seqGen.generateFibonacci()
    let seq = seqGen.getSequence()
    let processedSeq = processSequence(seq: seq)
    let (mean, maxVal, minVal) = analyzeSequence(seq: processedSeq)
    print("Mean:", mean, "Max:", maxVal, "Min:", minVal)
}

main()