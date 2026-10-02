import Foundation

func permuteData(_ data1: [Double], _ data2: [Double]) -> ([Double], [Double]) {
    var combined = data1 + data2
    combined.shuffle()
    let mid = combined.count / 2
    return (Array(combined.prefix(mid)), Array(combined.dropFirst(mid)))
}

func calculatePValue(_ data1: [Double], _ data2: [Double], iterations: Int = 1000) -> Double {
    let originalDiff = data1.mean() - data2.mean()
    var largerDiffCount = 0
    for _ in 0..<iterations {
        let (permutedData1, permutedData2) = permuteData(data1, data2)
        let permutedDiff = permutedData1.mean() - permutedData2.mean()
        if permutedDiff >= originalDiff {
            largerDiffCount += 1
        }
    }
    return Double(largerDiffCount) / Double(iterations)
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: 0...1) }
    let data2 = (0..<100).map { _ in Double.random(in: 0.5...1.5) }
    let pValue = calculatePValue(data1, data2)
    print(pValue)
}

extension Array where Element == Double {
    func mean() -> Double {
        return self.reduce(0, +) / Double(self.count)
    }
}

main()