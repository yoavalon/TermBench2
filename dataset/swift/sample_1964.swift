swift
import Foundation

func simulate_paths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: N + 1), count: M)
    for i in 0..<M {
        paths[i][0] = S0
    }
    for t in 1...N {
        let z = Array(repeating: Double.random(in: -1...1), count: M).map { sqrt(1 - $0 * $0) * cos(2 * Double.pi * Double.random(in: 0..<1)) }
        for i in 0..<M {
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func option_price(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.map { max($0.last! - K, 0) }
    return exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 252
    let M = 10000
    let paths = simulate_paths(S0: S0, mu: r, sigma: 0.2, T: T, N: N, M: M)
    let price = option_price(paths: paths, K: K, r: r, T: T)
    print("Option price: \(String(format: "%.2f", price))")
}

main()