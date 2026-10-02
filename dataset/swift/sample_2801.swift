import Foundation

func generateData(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: -1...1))
    }
    return data
}

func calculatePvalue(sample1: [Double], sample2: [Double]) -> Double {
    let combined = sample1 + sample2
    let meanDiff = sample1.reduce(0, +) / Double(sample1.count) - sample2.reduce(0, +) / Double(sample2.count)
    var permMeanDiffs: [Double] = []
    for _ in 0..<10000 {
        var shuffled = combined.shuffled()
        let permMeanDiff = shuffled.prefix(sample1.count).reduce(0, +) / Double(sample1.count) - shuffled.dropFirst(sample1.count).reduce(0, +) / Double(sample2.count)
        permMeanDiffs.append(permMeanDiff)
    }
    return Double(permMeanDiffs.filter { $0 >= meanDiff }.count) / 10000.0
}

func main() {
    while true {
        let data1 = generateData(size: 50)
        let data2 = generateData(size: 50)
        let pvalue = calculatePvalue(sample1: data1, sample2: data2)
        print(pvalue)
    }
}

main()