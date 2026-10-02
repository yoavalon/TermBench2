swift
import Foundation

func simulate_paths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = [[S0]](repeating: [S0], count: M)
    for t in 1...N {
        for i in 0..<M {
            let z = Double.random(in: 0...1)
            let newPrice = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z)
            paths[i].append(newPrice)
        }
    }
    return paths
}

func calculate_payoffs(paths: [[Double]], K: Double, T: Double, r: Double, type: String = "call") -> [Double] {
    var payoffs = [Double]()
    for path in paths {
        let ST = path.last!
        let payoff: Double
        if type == "call" {
            payoff = max(0, ST - K)
        } else {
            payoff = max(0, K - ST)
        }
        payoffs.append(payoff * exp(-r * T))
    }
    return payoffs
}

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, M: Int) -> Double {
    let paths = simulate_paths(S0: S0, mu: r, sigma: sigma, T: T, N: 100, M: M)
    let payoffs = calculate_payoffs(paths: paths, K: K, T: T, r: r)
    return payoffs.reduce(0, +) / Double(M)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let M = 10000
    let price = monte_carlo_pricing(S0: S0, K: K, T: T, r: r, sigma: sigma, M: M)
    print("Option Price: \(price, specifier: "%.2f")")
}

main()