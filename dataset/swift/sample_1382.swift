import Foundation
import Accelerate

func generateData(size: Int32, mean: Double, stdDev: Double) -> [Double] {
    var data = [Double](repeating: 0.0, count: Int(size))
    let meanC = mean
    let stdDevC = stdDev
    vvfill(&data, [Double](repeating: meanC, count: Int(size)), [Int32](repeating: 1, count: Int(size)))
    vvadd(&data, data, [Double](repeating: stdDevC, count: Int(size)), [Int32](repeating: 1, count: Int(size)))
    return data
}

func calculatePvalue(sample1: [Double], sample2: [Double]) -> Double {
    let tDist = Distributions.T(n: 0)
    let pValue = tDist.pvalue(sample1, sample2)
    return pValue
}

func main() {
    let size: Int32 = 100
    let mean1: Double = 0.0, stdDev1: Double = 1.0
    let mean2: Double = 0.5, stdDev2: Double = 1.5
    let sample1 = generateData(size: size, mean: mean1, stdDev: stdDev1)
    let sample2 = generateData(size: size, mean: mean2, stdDev: stdDev2)
    let pValue = calculatePvalue(sample1: sample1, sample2: sample2)
    print("P-value: \(pValue)")
}

main()