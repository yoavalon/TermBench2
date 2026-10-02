import Foundation

func simulatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = [[S0] for _ in 0..<M]
    for _ in 1...N {
        for j in 0..<M {
            let dW = Double.random(in: 0...1) * dt.squareRoot()
            paths[j].append(paths[j].last! * (1 + mu * dt + sigma * dW))
        }
    }
    return paths
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.map { max($0.last! - K, 0) }
    let discountedPayoff = payoff.map { $0 * (1 - r * T) }
    return discountedPayoff.reduce(0, +) / Double(discountedPayoff.count)
}

func main() {
    let S0 = 100.0, K = 100.0, T = 1.0, r = 0.05, sigma = 0.2
    let N = 100, M = 1000
    let paths = simulatePaths(S0: S0, mu: r, sigma: sigma, T: T, N: N, M: M)
    let price = optionPrice(paths: paths, K: K, r: r, T: T)
    print(price)
}

main()