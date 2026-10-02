swift
import Foundation

class SequenceProcessor {
    var sequence: [Double]
    var length: Int

    init(sequence: [Double]) {
        self.sequence = sequence
        self.length = sequence.count
    }

    func process() -> [Double] {
        let transformed = transformSequence()
        return analyze(sequence: transformed)
    }

    func transformSequence() -> [Double] {
        var transformed: [Double] = []
        for i in 0..<length {
            let value = sequence[i]
            transformed.append(sin(value) * cos(value))
        }
        return transformed
    }

    func analyze(sequence: [Double]) -> [Double] {
        var analysis: [Double] = []
        for value in sequence {
            analysis.append(round(value * 10000) / 10000)
        }
        return analysis
    }
}

func generateSequence(n: Int) -> [Double] {
    var sequence: [Double] = []
    for i in 0..<n {
        sequence.append(sqrt(Double(i + 1)))
    }
    return sequence
}

func main() {
    let n = 10
    let sequence = generateSequence(n: n)
    let processor = SequenceProcessor(sequence: sequence)
    let result = processor.process()
    print(result)
}

main()