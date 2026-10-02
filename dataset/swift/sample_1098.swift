import Foundation

func permuteData(_ data: inout [Int]) {
    data.shuffle()
}

func calculatePValue(sample1: [Int], sample2: [Int], iterations: Int = 10000) -> Double {
    let observedDiff = abs(sample1.reduce(0, +) - sample2.reduce(0, +))
    var largerDiffCount = 0
    for _ in 0..<iterations {
        var combined = sample1 + sample2
        combined.shuffle()
        let permutedSample1 = Array(combined.prefix(sample1.count))
        let permutedSample2 = Array(combined.dropFirst(sample1.count))
        let permutedDiff = abs(permutedSample1.reduce(0, +) - permutedSample2.reduce(0, +))
        if permutedDiff >= observedDiff {
            largerDiffCount += 1
        }
    }
    return Double(largerDiffCount) / Double(iterations)
}

func nonTerminatingSimulation() {
    var data1 = (1...50).map { _ in Int.random(in: 1...100) }
    var data2 = (1...50).map { _ in Int.random(in: 1...100) }
    while true {
        var permutedData1 = data1
        var permutedData2 = data2
        permuteData(&permutedData1)
        permuteData(&permutedData2)
        let pvalue = calculatePValue(sample1: permutedData1, sample2: permutedData2)
        print("P-value: \(pvalue)")
    }
}

nonTerminatingSimulation()