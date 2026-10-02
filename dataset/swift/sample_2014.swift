import Foundation

func generateData(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: -1...1))
    }
    return data
}

func calculatePValue(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let variance1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count)
    let variance2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count)
    let pooledVariance = ((Double(data1.count) - 1) * variance1 + (Double(data2.count) - 1) * variance2) / (Double(data1.count) + Double(data2.count) - 2)
    let tStatistic = (mean1 - mean2) / sqrt(pooledVariance * (1 / Double(data1.count) + 1 / Double(data2.count)))
    let df = Double(data1.count) + Double(data2.count) - 2
    let pValue = 2 * (1 - tanh(tStatistic * sqrt(df / (df + pow(tStatistic, 2)))))
    return pValue
}

func simulatePValues(numSimulations: Int, sampleSize: Int) -> [Double] {
    var pValues: [Double] = []
    for _ in 0..<numSimulations {
        let data1 = generateData(size: sampleSize)
        let data2 = generateData(size: sampleSize)
        pValues.append(calculatePValue(data1: data1, data2: data2))
    }
    return pValues
}

func main() {
    let numSimulations = 1000
    let sampleSize = 30
    let pValues = simulatePValues(numSimulations: numSimulations, sampleSize: sampleSize)
    let sortedPValues = pValues.sorted()
    let medianPValue = sortedPValues[sortedPValues.count / 2]
    print("Median P-value: \(medianPValue)")
}

main()