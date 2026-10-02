import Foundation

func simulatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M + 1), count: N + 1)
    paths[0][0] = S0
    for t in 1...N {
        let Z = (0..<M).map { _ in Double.random(in: -1...1) }
        for m in 0..<M {
            paths[t][m] = paths[t - 1][m] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[m])
        }
    }
    return paths
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double, N: Int) -> Double {
    let discountedPayoffs = paths[N].map { exp(-r * T) * max($0 - K, 0) }
    return discountedPayoffs.reduce(0, +) / Double(paths[N].count)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let paths = simulatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = optionPrice(paths: paths, K: K, r: r, T: T, N: N)
    print(price)
}

main()