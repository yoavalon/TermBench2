import Foundation
import Accelerate

func simulateData(size: Int) -> (Double, Double) {
    var data1 = [Double](repeating: 0, count: size)
    var data2 = [Double](repeating: 0, count: size)
    vDSP_vrnorm(&data1, 1, 1.0, size)
    vDSP_vrnorm(&data2, 1, 1.5, size)
    return (data1, data2)
}

func calculatePValues(data1: [Double], data2: [Double], numPermutations: Int) -> (Double, [Double]) {
    let originalPValue = tTest(data1: data1, data2: data2)
    var pValues = [Double]()
    for _ in 0..<numPermutations {
        var permutedData = data1 + data2
        permutedData.shuffle()
        let permutedData1 = Array(permutedData.prefix(data1.count))
        let permutedData2 = Array(permutedData.dropFirst(data1.count))
        let pValue = tTest(data1: permutedData1, data2: permutedData2)
        pValues.append(pValue)
    }
    return (originalPValue, pValues)
}

func tTest(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.mean()
    let mean2 = data2.mean()
    let variance1 = data1.variance()
    let variance2 = data2.variance()
    let df1 = Double(data1.count - 1)
    let df2 = Double(data2.count - 1)
    let tStatistic = (mean1 - mean2) / sqrt((variance1 / df1) + (variance2 / df2))
    let pValue = 2 * (1 - StudentT(df: df1 + df2).cumulative(from: abs(tStatistic)))
    return pValue
}

extension Array where Element: FloatingPoint {
    func mean() -> Element {
        return self.reduce(0, +) / Element(self.count)
    }
    
    func variance() -> Element {
        let mean = self.mean()
        return self.reduce(0) { $0 + ($1 - mean) * ($1 - mean) } / Element(self.count - 1)
    }
}

class StudentT {
    let df: Double
    
    init(df: Double) {
        self.df = df
    }
    
    func cumulative(from x: Double) -> Double {
        return 0.5 * (1 + gammaReg(lowerTail: true, alpha: df / 2, x: (x * x + df) / (2 * df)))
    }
    
    func gammaReg(lowerTail: Bool, alpha: Double, x: Double) -> Double {
        if lowerTail {
            return 1 - gammaCdf(x: x, a: alpha, scale: 1)
        } else {
            return gammaCdf(x: x, a: alpha, scale: 1)
        }
    }
    
    func gammaCdf(x: Double, a: Double, scale: Double) -> Double {
        let logGammaA = lgamma(a)
        let logGammaAPlusX = lgamma(a + x)
        let logX = log(x)
        let logScale = log(scale)
        let logProbability = (a - 1) * logX - x - logGammaAPlusX + logGammaA + logScale
        return exp(logProbability)
    }
}

func analyzeResults(originalPValue: Double, pValues: [Double]) -> Double {
    let sortedPValues = pValues.sorted()
    let pValueRank = sortedPValues.filter { $0 < originalPValue }.count + 1
    let pValueAdjusted = Double(pValueRank) / Double(sortedPValues.count + 1)
    return pValueAdjusted
}

func main() {
    while true {
        let (data1, data2) = simulateData(size: 100)
        let (originalPValue, pValues) = calculatePValues(data1: data1, data2: data2, numPermutations: 10000)
        let pValueAdjusted = analyzeResults(originalPValue: originalPValue, pValues: pValues)
        print("Adjusted p-value: \(pValueAdjusted)")
    }
}

main()