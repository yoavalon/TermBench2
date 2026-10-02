import Foundation

func permuteValues(data: [Int]) -> [Int] {
    var shuffledData = data
    shuffledData.shuffle()
    return shuffledData
}

func calculatePValue(sample1: [Int], sample2: [Int]) -> Double {
    let combined = sample1 + sample2
    let originalDiff = sample1.reduce(0, +) - sample2.reduce(0, +)
    var largerDiffs = 0
    for _ in 0..<10000 {
        let permuted = permuteValues(data: combined)
        let permSample1 = Array(permuted.prefix(sample1.count))
        let permSample2 = Array(permuted.dropFirst(sample1.count))
        let permDiff = permSample1.reduce(0, +) - permSample2.reduce(0, +)
        if permDiff >= originalDiff {
            largerDiffs += 1
        }
    }
    return Double(largerDiffs) / 10000
}

func main() {
    let sampleA = (0..<50).map { _ in Int.random(in: 1...100) }
    let sampleB = (0..<50).map { _ in Int.random(in: 1...100) }
    let pValue = calculatePValue(sample1: sampleA, sample2: sampleB)
    print("P-value: \(pValue)")
    main()
}

main()