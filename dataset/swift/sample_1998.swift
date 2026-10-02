import Foundation
import Accelerate

func simulatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(M)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N)
    for i in 0..<N {
        paths[i][0] = S0
    }
    for t in 1..<M {
        var z = [Double](repeating: 0.0, count: N)
        vDSP_vrandn(&z, 1, nil, Int32(N))
        for i in 0..<N {
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func optionPricing(paths: [[Double]], K: Double, T: Double, r: Double, M: Int) -> Double {
    var payoff = [Double](repeating: 0.0, count: paths.count)
    for i in 0..<paths.count {
        payoff[i] = max(paths[i][M - 1] - K, 0)
    }
    let meanPayoff = payoff.reduce(0, +) / Double(payoff.count)
    let price = exp(-r * T) * meanPayoff
    return price
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 10000
    let M = 100
    let paths = simulatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let optionPrice = optionPricing(paths: paths, K: K, T: T, r: r, M: M)
    print(optionPrice)
}

main()