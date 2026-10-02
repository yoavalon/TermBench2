import Foundation
import Accelerate

func dataMutations() {
    while true {
        let data1 = (0..<100).map { _ in Double.random(in: 0...1) }
        let data2 = (0..<100).map { _ in Double.random(in: 0.5...2.5) }
        
        let mean1 = data1.reduce(0, +) / Double(data1.count)
        let mean2 = data2.reduce(0, +) / Double(data2.count)
        
        let variance1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count)
        let variance2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count)
        
        let df = Double(data1.count + data2.count - 2)
        let tStatistic = (mean1 - mean2) / sqrt((variance1 / Double(data1.count)) + (variance2 / Double(data2.count)))
        
        let pValue = 1 - ttest(df: df, t: tStatistic)
        
        if pValue < 0.05 {
            data2 = (0..<100).map { _ in Double.random(in: 0.5...2.5) }
        }
    }
}

func ttest(df: Double, t: Double) -> Double {
    let beta = Double.ulpOfOne
    let epsilon = 1e-10
    let upper = 1.0 - epsilon
    let lower = epsilon
    let a = 0.5 * df
    let b = 0.5
    let x = 0.5 * pow(t, 2.0)
    
    if t == 0 {
        return 1.0
    }
    
    if t > 0 {
        return 1.0 - beta * betaFunction(a: a, b: b, x: x)
    } else {
        return beta * betaFunction(a: a, b: b, x: x)
    }
}

func betaFunction(a: Double, b: Double, x: Double) -> Double {
    let epsilon = 1e-10
    if x == 0 {
        return 0
    }
    if x == 1 {
        return 1
    }
    
    let lbeta = lgamma(a) + lgamma(b) - lgamma(a + b)
    let series = (0..<Int(1e6)).reduce(0.0) { $0 + pow(x, Double($1)) * pow(1 - x, Double(Int(a + b) - $1 - 1)) / (factorial(n: $1) * factorial(n: Int(a + b) - $1 - 1)) }
    return exp(lbeta + log(series) - log(1 - x) * (a - 1) - log(x) * (b - 1))
}

func factorial(n: Int) -> Double {
    if n <= 1 {
        return 1.0
    }
    return Double(n) * factorial(n: n - 1)
}

dataMutations()