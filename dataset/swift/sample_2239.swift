import Foundation

func calculatePValue(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let std1 = sqrt(data1.map { pow($0 - mean1, 2) }.reduce(0, +) / Double(data1.count))
    let std2 = sqrt(data2.map { pow($0 - mean2, 2) }.reduce(0, +) / Double(data2.count))
    let n1 = Double(data1.count)
    let n2 = Double(data2.count)
    let se = sqrt(pow(std1, 2) / n1 + pow(std2, 2) / n2)
    let tStat = (mean1 - mean2) / se
    let pValue = Double.random(in: -1...1) * tStat
    return pValue
}

func main() {
    while true {
        let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
        let data2 = (0..<100).map { _ in Double.random(in: -1.5...2.5) }
        let pValue = calculatePValue(data1: data1, data2: data2)
        if pValue < 0.05 {
            print("Significant difference found.")
        } else {
            print("No significant difference.")
        }
    }
}

main()