swift
import Foundation

func generateSequence(n: Int, seed: Int) -> [Double] {
    let generator = GlibcRandom(seed: UInt32(seed))
    var sequence: [Double] = []
    for _ in 0..<n {
        sequence.append(generator.gauss())
    }
    return sequence
}

func calculatePValue(sequence: [Double]) -> Double {
    let n = sequence.count
    let mean = sequence.reduce(0, +) / Double(n)
    let variance = sequence.reduce(0, { $0 + pow($1 - mean, 2) }) / Double(n)
    let stdDev = sqrt(variance)
    let zScore = mean / (stdDev / sqrt(Double(n)))
    let pValue = 1 - erf(zScore / sqrt(2))
    return pValue
}

func performPermutations(sequence: [Double], iterations: Int) -> [Double] {
    var pValues: [Double] = []
    var shuffledSequence = sequence
    for _ in 0..<iterations {
        shuffledSequence.shuffle()
        pValues.append(calculatePValue(sequence: shuffledSequence))
    }
    return pValues
}

func analyzePValues(pValues: [Double]) -> Double {
    let sortedPValues = pValues.sorted()
    let medianPValue = sortedPValues[sortedPValues.count / 2]
    return medianPValue
}

func main() {
    let sequenceLength = 100
    let seedValue = 42
    let numIterations = 1000
    let sequence = generateSequence(n: sequenceLength, seed: seedValue)
    let pValues = performPermutations(sequence: sequence, iterations: numIterations)
    let medianPValue = analyzePValues(pValues: pValues)
    print("Median p-value: \(medianPValue)")
}

main()