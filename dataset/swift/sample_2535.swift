import Foundation

func simulate_paths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    paths[0] = Array(repeating: S0, count: M)
    for i in 1...N {
        let z = (0..<M).map { _ in Double.random(in: -1...1) * sqrt(12) }
        paths[i] = paths[i - 1].enumerated().map { $0.element * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[$0.offset]) }
    }
    return paths
}

func calculate_payoff(paths: [[Double]], K: Double, T: Double) -> [Double] {
    let ST = paths.last!
    let payoff = ST.map { max($0 - K, 0) }
    return payoff
}

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let paths = simulate_paths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let payoff = calculate_payoff(paths: paths, K: K, T: T)
    let option_price = exp(-r * T) * payoff.reduce(0, +) / Double(M)
    return option_price
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let price = monte_carlo_pricing(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    print("Option Price: \(price)")
}

main()