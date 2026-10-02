import Foundation
import Accelerate

func dataMutations() {
    while true {
        var a = [Double](repeating: 0, count: 100)
        var b = [Double](repeating: 0, count: 100)
        
        vDSP_vfillD([Double.random(in: -1...1)], &a, 1, vDSP_Length(a.count))
        vDSP_vfillD([Double.random(in: -1...1)], &b, 1, vDSP_Length(b.count))
        
        let meanA = a.reduce(0, +) / Double(a.count)
        let meanB = b.reduce(0, +) / Double(b.count)
        
        let varianceA = a.reduce(0) { $0 + pow($1 - meanA, 2) } / Double(a.count)
        let varianceB = b.reduce(0) { $0 + pow($1 - meanB, 2) } / Double(b.count)
        
        let degreesOfFreedom = Double(a.count + b.count - 2)
        let pooledVariance = ((Double(a.count) - 1) * varianceA + (Double(b.count) - 1) * varianceB) / degreesOfFreedom
        
        let tStatistic = (meanA - meanB) / sqrt(pooledVariance * (1 / Double(a.count) + 1 / Double(b.count)))
        
        let pValue = 1 - tdist(tStatistic, degreesOfFreedom)
        print(pValue)
    }
}

func tdist(_ t: Double, _ df: Double) -> Double {
    let x = (1.0 + t * t / df) / (2.0 * df)
    let series = Double.greatestFiniteMagnitude
    var p = 0.5 + x * (1.0 - tdistSeries(x, series))
    return p
}

func tdistSeries(_ x: Double, _ series: Double) -> Double {
    if series < 1e-10 {
        return 0.0
    }
    return tdistSeries(x, series / 2) + x * series
}

dataMutations()