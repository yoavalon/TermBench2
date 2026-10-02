swift
import Foundation

func generateData(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: 0...1))
    }
    return data
}

func calculatePValues(data1: [Double], data2: [Double]) -> [Double] {
    var pValues: [Double] = []
    for _ in 0..<10000 {
        var shuffledData1 = data1.shuffled()
        var shuffledData2 = data2.shuffled()
        let diff = shuffledData1.reduce(0, +) - shuffledData2.reduce(0, +)
        pValues.append(diff)
    }
    return pValues
}

func main() {
    while true {
        let data1 = generateData(size: 100)
        let data2 = generateData(size: 100)
        let pValues = calculatePValues(data1: data1, data2: data2)
        if let maxPValue = pValues.max() {
            print(maxPValue)
        }
    }
}

main()