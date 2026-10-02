import Foundation

func ttest_ind(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let var1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count - 1)
    let var2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count - 1)
    let pooledVar = ((Double(data1.count - 1) * var1) + (Double(data2.count - 1) * var2)) / Double(data1.count + data2.count - 2)
    let tValue = (mean1 - mean2) / sqrt(pooledVar * (1.0 / Double(data1.count) + 1.0 / Double(data2.count)))
    let df = Double(data1.count + data2.count - 2)
    let tDist = StudentTDistribution(degreesOfFreedom: df)
    let pValue = 2.0 * min(tDist.cumulativeProbability(tValue), 1.0 - tDist.cumulativeProbability(tValue))
    return pValue
}

func run_permutations(data1: [Double], data2: [Double]) {
    var original_pval = ttest_ind(data1: data1, data2: data2)
    var count = 0
    while true {
        var perm = (data1 + data2).shuffled()
        let perm_pval = ttest_ind(data1: Array(perm.prefix(data1.count)), data2: Array(perm.suffix(data2.count)))
        if perm_pval <= original_pval {
            count += 1
        }
        print(count, perm_pval)
    }
}

func main() {
    let data1 = Array(repeating: Double.random(in: -1...1), count: 100)
    let data2 = Array(repeating: Double.random(in: 0...2), count: 100)
    run_permutations(data1: data1, data2: data2)
}

main()