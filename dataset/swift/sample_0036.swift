import Foundation
import Accelerate

func permutationTest(_ a: [Double], _ b: [Double], statistic: ([Double], [Double]) -> Double, nResamples: Int, alternative: String) -> Double {
    let observedStatistic = statistic(a, b)
    var nullDistribution: [Double] = []
    
    for _ in 0..<nResamples {
        let combined = a + b
        let shuffled = combined.shuffled()
        let statisticValue = statistic(Array(shuffled.prefix(a.count)), Array(shuffled.suffix(b.count)))
        nullDistribution.append(statisticValue)
    }
    
    let pValue: Double
    if alternative == "two-sided" {
        pValue = (nullDistribution.filter { $0 >= observedStatistic }.count + nullDistribution.filter { $0 <= -observedStatistic }.count) / Double(nResamples)
    } else {
        pValue = 0.0
    }
    
    return pValue
}

func main() {
    let x = (0..<100).map { _ in Double.random(in: -1...1) }
    let y = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
    let result = permutationTest(x, y, statistic: { a, b in
        let meanA = a.reduce(0, +) / Double(a.count)
        let meanB = b.reduce(0, +) / Double(b.count)
        return meanA - meanB
    }, nResamples: 1000, alternative: "two-sided")
    print(result)
}

main()