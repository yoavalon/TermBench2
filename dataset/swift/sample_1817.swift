import Foundation
import Accelerate

func financial_simulation(n: Int, s: Double, r: Double, t: Double, v: Double) -> Double {
    let dt = t / Double(n)
    var st = [Double](repeating: s, count: n)
    
    let mean = (r - 0.5 * v * v) * dt
    let stdDev = v * sqrt(dt)
    
    for i in 0..<n {
        st[i] *= exp(mean + stdDev * Double.random(in: -1...1))
    }
    
    let returns = st.map { max($0 - s, 0) }
    let sum = returns.reduce(0, +)
    return sum / Double(n)
}

financial_simulation(n: 10000, s: 100, r: 0.05, t: 1, v: 0.2)