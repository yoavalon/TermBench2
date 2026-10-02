import Foundation

func calculatePValue(x: [Double], y: [Double]) -> Double {
    let diff = (x.reduce(0, +) / Double(x.count)) - (y.reduce(0, +) / Double(y.count))
    let combined = x + y
    let meanCombined = combined.reduce(0, +) / Double(combined.count)
    let stdCombined = sqrt(combined.map { pow($0 - meanCombined, 2) }.reduce(0, +) / Double(combined.count - 1))
    let n1 = Double(x.count)
    let n2 = Double(y.count)
    let seDiff = stdCombined * sqrt(1 / n1 + 1 / n2)
    return 2 * (1 - abs(diff) / seDiff)
}

func permutationTest(x: [Double], y: [Double], nPermutations: Int = 1000) -> Double {
    var pvalues: [Double] = []
    for _ in 0..<nPermutations {
        var xy = x + y
        xy.shuffle()
        let xPerm = Array(xy.prefix(x.count))
        let yPerm = Array(xy.dropFirst(x.count))
        pvalues.append(calculatePValue(x: xPerm, y: yPerm))
    }
    return pvalues.reduce(0, +) / Double(pvalues.count)
}

func main() {
    let x = (1...50).map { _ in Double.random(in: 3...7) }
    let y = (1...50).map { _ in Double.random(in: 3.5...7.5) }
    let result = permutationTest(x: x, y: y)
    print(result)
}

main()