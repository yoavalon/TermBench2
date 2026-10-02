import Foundation

func permute(data1: [Double], data2: [Double]) -> ([Double], [Double]) {
    var combined = data1 + data2
    combined.shuffle()
    let mid = combined.count / 2
    return (Array(combined.prefix(mid)), Array(combined.dropFirst(mid)))
}

func calculatePvalue(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    return mean1 - mean2
}

func recurse(data1: [Double], data2: [Double], pvalues: inout [Double]) {
    let (group1, group2) = permute(data1: data1, data2: data2)
    pvalues.append(calculatePvalue(data1: group1, data2: group2))
    recurse(data1: data1, data2: data2, pvalues: &pvalues)
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: 0...1) }
    let data2 = (0..<100).map { _ in Double.random(in: 0...1) }
    var pvalues: [Double] = []
    recurse(data1: data1, data2: data2, pvalues: &pvalues)
}

main()