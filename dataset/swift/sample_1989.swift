import Foundation

func simulatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    paths[0] = Array(repeating: S0, count: M)
    for t in 1...N {
        let rand = (0..<M).map { _ in Double.random(in: -1...1) }
        paths[t] = (0..<M).map { i in
            paths[t - 1][i] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * rand[i])
        }
    }
    return paths
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.last!.map { max($0 - K, 0) }
    let meanPayoff = payoff.reduce(0, +) / Double(payoff.count)
    return exp(-r * T) * meanPayoff
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 252
    let M = 10000
    let paths = simulatePaths(S0: S0, mu: r, sigma: 0.2, T: T, N: N, M: M)
    let price = optionPrice(paths: paths, K: K, r: r, T: T)
    print("Option Price: \(price, specifier: "%.4f")")
}

main()