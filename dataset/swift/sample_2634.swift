import Foundation

func generateSequence(size: Int) -> [Double] {
    var sequence = [Double]()
    for _ in 0..<size {
        sequence.append(Double.random(in: 0...1))
    }
    sequence.sort()
    return sequence
}

func calculatePValue(sequence: [Double], alpha: Double) -> Double {
    let n = sequence.count
    let mean = sequence.reduce(0, +) / Double(n)
    let variance = sequence.reduce(0) { $0 + pow($1 - mean, 2) } / Double(n)
    let stdDev = sqrt(variance)
    let zScore = (mean - 0.5) / (stdDev / sqrt(Double(n)))
    let pValue = 2 * (1 - erf(abs(zScore) / sqrt(2)))
    return pValue
}

func performPermutations(sequence: [Double], alpha: Double, iterations: Int) -> [Double] {
    var pValues = [Double]()
    for _ in 0..<iterations {
        let permutedSequence = generateSequence(size: sequence.count)
        pValues.append(calculatePValue(sequence: permutedSequence, alpha: alpha))
    }
    return pValues
}

func main() {
    let size = 100
    let alpha = 0.05
    let iterations = 1000
    let originalSequence = generateSequence(size: size)
    let originalPValue = calculatePValue(sequence: originalSequence, alpha: alpha)
    let permutedPValues = performPermutations(sequence: originalSequence, alpha: alpha, iterations: iterations)
    let observedPValues = permutedPValues.filter { $0 <= originalPValue }
    let pValueOfPValue = Double(observedPValues.count) / Double(iterations)
    print(pValueOfPValue)
}

main()