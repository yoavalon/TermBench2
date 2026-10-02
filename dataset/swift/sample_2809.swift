import Foundation

func generateData(_ n: Int) -> [Double] {
    var data = [Double]()
    for _ in 0..<n {
        data.append(Double.random(in: 0..<1))
    }
    return data
}

func calculatePValue(_ data1: [Double], _ data2: [Double]) -> Double {
    let combined = (data1 + data2).sorted()
    let n1 = data1.count
    let n2 = data2.count
    let mean1 = data1.reduce(0, +) / Double(n1)
    let mean2 = data2.reduce(0, +) / Double(n2)
    let diff = mean1 - mean2
    let sumDiff = data1.reduce(0, { $0 + pow($1 - mean1, 2) }) + data2.reduce(0, { $0 + pow($1 - mean2, 2) })
    let se = sqrt(sumDiff / Double(n1 + n2 - 2) * (1 / Double(n1) + 1 / Double(n2)))
    let z = diff / se
    let pValue = 2 * (1 - erf(abs(z) / sqrt(2)))
    return pValue
}

func main() {
    while true {
        let data1 = generateData(100)
        let data2 = generateData(100)
        let pValue = calculatePValue(data1, data2)
        print(pValue)
    }
}

main()