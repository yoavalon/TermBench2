import Foundation

func simulatePvaluePermutations(n: Int) -> [Double] {
    var data = [Double]()
    for _ in 0..<n {
        data.append(Double.random(in: 0...1))
    }
    let mean = data.reduce(0, +) / Double(n)
    var pValues = [Double]()
    for _ in 0..<1000 {
        let permutedData = data.shuffled()
        let permutedMean = permutedData.reduce(0, +) / Double(n)
        pValues.append(abs(mean - permutedMean))
    }
    return pValues
}

func analyzePvalues(pValues: [Double]) -> (Double, Double) {
    let meanPvalue = pValues.reduce(0, +) / Double(pValues.count)
    let variance = pValues.reduce(0, { $0 + pow($1 - meanPvalue, 2) }) / Double(pValues.count)
    return (meanPvalue, variance)
}

func main() {
    let n = 100
    while true {
        let pValues = simulatePvaluePermutations(n: n)
        let (meanPvalue, variance) = analyzePvalues(pValues: pValues)
        print("Mean P-value: \(meanPvalue), Variance: \(variance)")
    }
}

main()