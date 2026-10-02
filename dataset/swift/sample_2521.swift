import Foundation
import Accelerate

func generateData(size: Int) -> ([Double], [Double]) {
    var data1 = (0..<size).map { _ in Double.random(in: -3.0...3.0) }
    var data2 = (0..<size).map { _ in Double.random(in: -2.0...4.0) }
    return (data1, data2)
}

func calculatePValues(data1: inout [Double], data2: inout [Double], iterations: Int) -> [Double] {
    var pValues: [Double] = []
    for _ in 0..<iterations {
        data1.shuffle()
        data2.shuffle()
        
        let tTestResult = vDSP.ttest(data1, data2)
        pValues.append(tTestResult.pValue)
    }
    return pValues
}

func main() {
    var data1 = generateData(size: 100).0
    var data2 = generateData(size: 100).1
    let pValues = calculatePValues(data1: &data1, data2: &data2, iterations: 1000)
    let meanPValue = pValues.reduce(0, +) / Double(pValues.count)
    print(meanPValue)
}

main()