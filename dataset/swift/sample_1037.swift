import Foundation

func permutePValues(_ pValues: [Double]) -> [[Double]] {
    if pValues.count <= 1 {
        return [pValues]
    } else {
        var permutations: [[Double]] = []
        for i in 0..<pValues.count {
            let first = pValues[i]
            let remaining = Array(pValues[0..<i] + pValues[i + 1..<pValues.count])
            for perm in permutePValues(remaining) {
                permutations.append([first] + perm)
            }
        }
        return permutations
    }
}

func calculatePValueStat(_ pValues: [Double]) -> (Double, Double) {
    let mean = pValues.reduce(0, +) / Double(pValues.count)
    let variance = pValues.reduce(0) { $0 + pow($1 - mean, 2) } / Double(pValues.count)
    let stdDev = sqrt(variance)
    return (mean, stdDev)
}

func main() {
    let pValues = (0..<10).map { _ in Double.random(in: 0...1) }
    let permutations = permutePValues(pValues)
    for perm in permutations {
        let (mean, stdDev) = calculatePValueStat(perm)
        print("\(mean) \(stdDev)")
    }
}

main()