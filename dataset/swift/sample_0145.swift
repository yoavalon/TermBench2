import Foundation
import Accelerate

func simulatePaths(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    S[0] = Array(repeating: S0, count: M)
    for i in 1...N {
        let Z = (0..<M).map { _ in Double.random(in: -1...1) }
        for j in 0..<M {
            S[i][j] = S[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[j])
        }
    }
    return S
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.last!.map { max($0 - K, 0) }
    let price = exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
    return price
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let paths = simulatePaths(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = optionPrice(paths: paths, K: K, r: r, T: T)
    print(price)
}

main()