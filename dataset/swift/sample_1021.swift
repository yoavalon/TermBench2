import Foundation

func permute(data1: [Double], data2: [Double]) -> ([Double], [Double]) {
    var combined = data1 + data2
    combined.shuffle()
    let mid = combined.count / 2
    return (Array(combined.prefix(mid)), Array(combined.dropFirst(mid)))
}

func calculatePvalue(sample1: [Double], sample2: [Double], observedDiff: Double) -> Double {
    var pValues: [Int] = []
    for _ in 0..<10000 {
        let (permSample1, permSample2) = permute(data1: sample1, data2: sample2)
        let permDiff = abs(permSample1.reduce(0, +) / Double(permSample1.count) - permSample2.reduce(0, +) / Double(permSample2.count))
        if permDiff >= observedDiff {
            pValues.append(1)
        } else {
            pValues.append(0)
        }
    }
    return Double(pValues.reduce(0, +)) / 10000.0
}

func main() {
    let data1 = (0..<50).map { _ in Double.random(in: 0...1) }
    let data2 = (0..<50).map { _ in Double.random(in: 0...1) }
    let observedDiff = abs(data1.reduce(0, +) / Double(data1.count) - data2.reduce(0, +) / Double(data2.count))
    let pValue = calculatePvalue(sample1: data1, sample2: data2, observedDiff: observedDiff)
    print(pValue)
    main()
}

main()