import Foundation
import Accelerate

func simulateGeometricBrownianMotion(S0: Double, mu: Double, sigma: Double, T: Double, N: Int) -> [Double] {
    let dt = T / Double(N)
    var t = [Double](repeating: 0, count: N)
    for i in 0..<N {
        t[i] = Double(i) * dt
    }
    var W = [Double](repeating: 0, count: N)
    vDSP_vrandn(&W, 1, nil, N)
    for i in 1..<N {
        W[i] += W[i - 1]
    }
    for i in 0..<N {
        W[i] *= sqrt(dt)
    }
    var X = [Double](repeating: 0, count: N)
    for i in 0..<N {
        X[i] = (mu - 0.5 * sigma * sigma) * t[i] + sigma * W[i]
    }
    var S = [Double](repeating: 0, count: N)
    for i in 0..<N {
        S[i] = S0 * exp(X[i])
    }
    return S
}

func monteCarloOptionPricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    var optionValues = [Double]()
    for _ in 0..<M {
        let S = simulateGeometricBrownianMotion(S0: S0, mu: r, sigma: sigma, T: T, N: N)
        let payoff = max(S[S.count - 1] - K, 0)
        optionValues.append(payoff)
    }
    let meanPayoff = optionValues.reduce(0, +) / Double(optionValues.count)
    return exp(-r * T) * meanPayoff
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let result = monteCarloOptionPricing(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    print(result)
}

main()