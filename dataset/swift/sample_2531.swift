import Foundation

func simulate_paths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    var paths = [[Double]](repeating: [S0], count: M)
    let dt = T / Double(N)
    for _ in 1...N {
        for i in 0..<M {
            let z = Double.random(in: -1...1) * sqrt(12) // Approximating Gaussian
            let S = paths[i][paths[i].count - 1] * (1 + mu * dt + sigma * z * sqrt(dt))
            paths[i].append(S)
        }
    }
    return paths
}

func calculate_option_price(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.map { max($0.last ?? 0, 0) }
    let price = payoff.reduce(0, +) * (1 / Double(payoff.count)) * (1 / (1 + r * T))
    return price
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 100
    let M = 1000
    let paths = simulate_paths(S0: S0, mu: r - 0.5 * 0.2 * 0.2, sigma: 0.2, T: T, N: N, M: M)
    let price = calculate_option_price(paths: paths, K: K, r: r, T: T)
    print(price)
}

main()