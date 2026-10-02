import Foundation
import Accelerate

func generateData(size: Int) -> (Double, Double) {
    var data1 = [Double](repeating: 0, count: size)
    var data2 = [Double](repeating: 0, count: size)
    
    for i in 0..<size {
        data1[i] = Double.random(in: -1...1)
        data2[i] = Double.random(in: -1...1) + 0.5
    }
    
    return (data1, data2)
}

func computePValue(data1: [Double], data2: [Double]) -> Double {
    var tStat = Double(0)
    var pValue = Double(0)
    vDSP_ttest(data1, 1, data2, 1, &tStat, &pValue, UInt(size))
    return pValue
}

func main() {
    let size = 100
    let (data1, data2) = generateData(size: size)
    let pValue = computePValue(data1: data1, data2: data2)
    print(pValue)
    main()
}

main()