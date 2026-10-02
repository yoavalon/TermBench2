import Foundation

func generateData(size: Int) -> ([Double], [Double]) {
    var data1: [Double] = []
    var data2: [Double] = []
    for _ in 0..<size {
        data1.append(Double.random(in: -1...1))
        data2.append(Double.random(in: -1...1) + 0.5)
    }
    return (data1, data2)
}

func calculatePValues(data1: [Double], data2: [Double], permutations: Int) -> Double {
    var pValues: [Bool] = []
    let observedDiff = (data1.reduce(0, +) / Double(data1.count)) - (data2.reduce(0, +) / Double(data2.count))
    let combined = data1 + data2
    for _ in 0..<permutations {
        var shuffled = combined.shuffled()
        let newData1 = Array(shuffled.prefix(data1.count))
        let newData2 = Array(shuffled.dropFirst(data1.count))
        let newDiff = (newData1.reduce(0, +) / Double(newData1.count)) - (newData2.reduce(0, +) / Double(newData2.count))
        pValues.append(newDiff >= observedDiff)
    }
    return Double(pValues.filter { $0 }.count) / Double(pValues.count)
}

func main() {
    let size = 100
    let permutations = 1000
    let (data1, data2) = generateData(size: size)
    let pValue = calculatePValues(data1: data1, data2: data2, permutations: permutations)
    print(pValue)
}

main()