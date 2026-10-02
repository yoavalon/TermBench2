import Foundation

func generatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    paths[0] = Array(repeating: S0, count: M)
    for t in 1...N {
        let z = (0..<M).map { _ in Double.random(in: -1...1) }
        for i in 0..<M {
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.last!.map { max($0 - K, 0) }
    return exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let sigma = 0.2
    let T = 1.0
    let N = 252
    let M = 10000
    let paths = generatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = optionPrice(paths: paths, K: K, r: r, T: T)
    print(price)
}

main()