import Foundation

func simulate_option_price(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S = S0
    for _ in 0..<N {
        S *= exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
    }
    return max(S - K, 0)
}

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, M: Int, N: Int) -> Double {
    var total = 0.0
    for _ in 0..<M {
        total += simulate_option_price(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    }
    return total / Double(M) * exp(-r * T)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let M = 1000
    let N = 100
    print(monte_carlo_pricing(S0: S0, K: K, T: T, r: r, sigma: sigma, M: M, N: N))
}

main()