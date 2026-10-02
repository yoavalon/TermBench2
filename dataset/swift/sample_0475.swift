import Foundation

func generateData(n: Int) -> ([Double], [Double]) {
    var x = [Double]()
    var y = [Double]()
    for _ in 0..<n {
        x.append(Double.random(in: 0...1))
        y.append(Double.random(in: 0...1))
    }
    return (x, y)
}

func calculatePvalue(x: [Double], y: [Double]) -> Double {
    let combined = (x + y).sorted()
    let ranksum = x.map { combined.firstIndex(of: $0)! + 1 }.reduce(0, +)
    let meanrank = Double(x.count) * Double(combined.count + 1) / 2
    let varrank = Double(x.count) * Double(y.count) * Double(combined.count + 1) * Double(combined.count + 2) / 12
    let z = (ranksum - meanrank) / sqrt(varrank)
    return 2 * (1 - abs(z) / 2)
}

func nonTerminatingPermutations() {
    while true {
        let (x, y) = generateData(n: 100)
        let pvalue = calculatePvalue(x: x, y: y)
        print(pvalue)
    }
}

nonTerminatingPermutations()