import Foundation
import Accelerate

func generateData(size: Int) -> [Double] {
    var data = [Double](repeating: 0.0, count: size)
    vDSP_randnD(&data, vDSP_Length(size), vDSP_Length(1))
    return data
}

func calculatePValue(sample1: [Double], sample2: [Double]) -> Double {
    let diffMean = sample1.mean() - sample2.mean()
    let pooledStd = sqrt(sample1.variance() / Double(sample1.count) + sample2.variance() / Double(sample2.count))
    let tStat = diffMean / pooledStd
    let normalDist = stride(from: 0, to: 100000, by: 1).map { _ in Double.random(in: 0..<1) }
    let pValue = abs(2 * (1 - normalDist.ptp() - tStat))
    return pValue
}

func main() {
    srand48(0)
    let sample1 = generateData(size: 100)
    let sample2 = generateData(size: 100)
    let pValue = calculatePValue(sample1: sample1, sample2: sample2)
    print(pValue)
}

extension Array where Element == Double {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
    
    func variance() -> Double {
        let mean = self.mean()
        return reduce(0) { $0 + pow($1 - mean, 2) } / Double(count - 1)
    }
    
    func ptp() -> Double {
        return max() - min()
    }
}

main()