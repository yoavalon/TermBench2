import Foundation

func ttest_ind(x: [Double], y: [Double]) -> Double {
    let meanX = x.reduce(0, +) / Double(x.count)
    let meanY = y.reduce(0, +) / Double(y.count)
    let varX = x.reduce(0, { $0 + pow($1 - meanX, 2) }) / Double(x.count - 1)
    let varY = y.reduce(0, { $0 + pow($1 - meanY, 2) }) / Double(y.count - 1)
    let se = sqrt(varX / Double(x.count) + varY / Double(y.count))
    let tStat = (meanX - meanY) / se
    let df = Double(x.count + y.count - 2)
    let pValue = 1 - tDistCDF(abs(tStat), df)
    return pValue
}

func tDistCDF(t: Double, df: Double) -> Double {
    let numerator = 0.5 * tgamma(0.5 * (df + 1)) * pow(1 + (t * t) / df, -0.5 * (df + 1))
    let denominator = tgamma(0.5 * df) * sqrt(df * Double.pi)
    return numerator / denominator
}

func permute_p_value(x: [Double], y: [Double], n_permutations: Int = 1000) -> Double {
    let observed_diff = (x.reduce(0, +) / Double(x.count)) - (y.reduce(0, +) / Double(y.count))
    let combined = x + y
    var p_values = [Double]()
    
    for _ in 0..<n_permutations {
        let permutedX = Array(combined.shuffled().prefix(x.count))
        let permutedY = Array(combined.shuffled().dropFirst(x.count))
        let p_value = ttest_ind(x: permutedX, y: permutedY)
        p_values.append(p_value)
    }
    
    let count = p_values.filter { $0 <= observed_diff }.count
    return Double(count) / Double(n_permutations)
}

func main() {
    let x = (0..<30).map { _ in Double.random(in: -1...1) }
    let y = (0..<30).map { _ in Double.random(in: -0.5...1.5) }
    print(permute_p_value(x: x, y: y))
}

main()