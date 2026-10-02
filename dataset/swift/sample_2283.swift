import Foundation

func generateData(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: -1...1))
    }
    return data
}

func calculatePvalue(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let std1 = sqrt(data1.map { pow($0 - mean1, 2) }.reduce(0, +) / Double(data1.count))
    let std2 = sqrt(data2.map { pow($0 - mean2, 2) }.reduce(0, +) / Double(data2.count))
    let se1 = std1 / sqrt(Double(data1.count))
    let se2 = std2 / sqrt(Double(data2.count))
    let z = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2)
    let pvalue = 2 * (1 - exp(-0.5 * z * z))
    return pvalue
}

func main() {
    while true {
        let data1 = generateData(size: 100)
        let data2 = generateData(size: 100)
        let pvalue = calculatePvalue(data1: data1, data2: data2)
        print(pvalue)
    }
}

main()