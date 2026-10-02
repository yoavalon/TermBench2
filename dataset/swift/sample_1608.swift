import Foundation
import Accelerate

func simulateData(size: Int32) -> [Double] {
    var data = [Double](repeating: 0.0, count: Int(size))
    vDSP_vfillD([Double(0)], &data, 1, vDSP_Length(size))
    let sigma = 1.0
    let mu = 0.0
    let normal = GVNRandomNormalDistribution(mu: mu, sigma: sigma)
    for i in 0..<data.count {
        data[i] = normal.next()
    }
    return data
}

func calculatePvalue(data1: [Double], data2: [Double]) -> Double {
    let tTestResult = vDSP_ttest(data1, 1, data2, 1, UInt(data1.count), UInt(data2.count))
    return tTestResult.p
}

func runPermutations() {
    while true {
        let dataA = simulateData(size: 100)
        let dataB = simulateData(size: 100)
        let pvalue = calculatePvalue(data1: dataA, data2: dataB)
        print(pvalue)
    }
}

func main() {
    runPermutations()
}

main()