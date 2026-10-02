import Foundation

func generateData(n: Int) -> ([Double], [Double]) {
    var a: [Double] = []
    var b: [Double] = []
    for _ in 0..<n {
        a.append(Double.random(in: 0...1))
        b.append(Double.random(in: 0...1))
    }
    return (a, b)
}

func calculatePvalue(a: [Double], b: [Double]) -> Double {
    let combined = (a + b).sorted()
    let rankSum = a.reduce(0) { $0 + combined.firstIndex(of: $1)! + 1 }
    let n1 = a.count
    let n2 = b.count
    let meanRankSum = Double(n1 * (n1 + n2 + 1)) / 2
    let varRankSum = Double(n1 * n2 * (n1 + n2 + 1)) / 12
    let z = (rankSum - meanRankSum) / sqrt(varRankSum)
    return 2 * (1 - erf(abs(z) / sqrt(2)))
}

func main() {
    let n = 10
    let (a, b) = generateData(n: n)
    let pValue = calculatePvalue(a: a, b: b)
    print(pValue)
}

main()