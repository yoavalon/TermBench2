import Foundation
import Accelerate

func simulatePValues(nTrials: Int, sampleSize: Int) -> [Double] {
    var data = [Double](repeating: 0.0, count: nTrials * sampleSize)
    for i in 0..<nTrials {
        for j in 0..<sampleSize {
            data[i * sampleSize + j] = Double.random(in: -1.0...1.0)
        }
    }
    
    var pValues: [Double] = []
    for i in 0..<nTrials {
        var mean: Double = 0
        var variance: Double = 0
        var n: Double = Double(sampleSize)
        
        for j in 0..<sampleSize {
            mean += data[i * sampleSize + j]
        }
        mean /= n
        
        for j in 0..<sampleSize {
            variance += pow(data[i * sampleSize + j] - mean, 2)
        }
        variance /= (n - 1)
        
        let tStat = (mean - 0) / sqrt(variance / n)
        let pVal = tDistribution(t: tStat, df: Int(n - 1))
        pValues.append(pVal)
    }
    
    return pValues
}

func tDistribution(t: Double, df: Int) -> Double {
    let upperTail = 1 - Double(GSL_sf_hypgeom_P(k: df, N: df, n: df, t: Int(t)))
    return upperTail
}

func analyzePValues(pValues: [Double], threshold: Double) -> Int {
    var significantCount = 0
    for p in pValues {
        if p < threshold {
            significantCount += 1
        }
    }
    return significantCount
}

func main() {
    let nTrials = 1000
    let sampleSize = 30
    let threshold = 0.05
    let pValues = simulatePValues(nTrials: nTrials, sampleSize: sampleSize)
    let result = analyzePValues(pValues: pValues, threshold: threshold)
    print(result)
}

main()