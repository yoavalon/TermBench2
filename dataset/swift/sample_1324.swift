import Foundation

func generate_data(size: Int) -> ([Double], [Double]) {
    let group1 = (0..<size).map { _ in Double.random(in: 1...9) }
    let group2 = (0..<size).map { _ in Double.random(in: 1...9) }
    return (group1, group2)
}

func calculate_pvalue_permutations(group1: [Double], group2: [Double], iterations: Int) -> [Double] {
    var pvalues: [Double] = []
    let combined = group1 + group2
    for _ in 0..<iterations {
        var shuffled = combined.shuffled()
        let permuted_group1 = Array(shuffled.prefix(group1.count))
        let permuted_group2 = Array(shuffled.dropFirst(group1.count))
        let tStat = ttest_ind(permuted_group1, permuted_group2)
        pvalues.append(tStat.pValue)
    }
    return pvalues
}

func ttest_ind(_ group1: [Double], _ group2: [Double]) -> (tStat: Double, pValue: Double) {
    let mean1 = group1.average
    let mean2 = group2.average
    let var1 = group1.variance
    let var2 = group2.variance
    let n1 = Double(group1.count)
    let n2 = Double(group2.count)
    let se = sqrt((var1 / n1) + (var2 / n2))
    let tStat = (mean1 - mean2) / se
    let df = (var1 / n1 + var2 / n2) * (var1 / n1 + var2 / n2) / (((var1 / n1) * (var1 / n1)) / (n1 - 1) + ((var2 / n2) * (var2 / n2)) / (n2 - 1))
    let pValue = t_cdf(tStat, df: Int(df))
    return (tStat, pValue)
}

extension Array where Element: FloatingPoint {
    var average: Element {
        return reduce(0, +) / Element(count)
    }
    
    var variance: Element {
        let avg = average
        return reduce(0) { $0 + ($1 - avg) * ($1 - avg) } / Element(count - 1)
    }
}

func t_cdf(_ t: Double, df: Int) -> Double {
    let beta = 0.00000000001
    let alpha = 0.00001
    let maxIterations = 100000
    var x = t / sqrt(Double(df))
    var num = 0.0
    var den = 1.0
    var tnum = 1.0
    var tden = 1.0
    var term = 1.0
    var i = 1
    while abs(term) > beta && i <= maxIterations {
        tnum *= x * x * Double(i - 1) / (2 * i - 1)
        tden *= Double(df + 2 * i - 2) * Double(df + 2 * i - 1)
        term = tnum / tden
        num += term
        den += term * Double(df + 2 * i - 1) / (2 * i)
        i += 1
    }
    let result = 0.5 + (num / (pow(Double(df), 0.5) * den * tgamma(Double(df / 2 + 1)) / tgamma(Double(df / 2))))
    return result
}

func main() {
    let (group1, group2) = generate_data(size: 30)
    let permutations = 1000
    let pvalues = calculate_pvalue_permutations(group1: group1, group2: group2, iterations: permutations)
    print(pvalues.average)
}

main()