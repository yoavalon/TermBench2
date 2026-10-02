import Foundation

func simulate_monte_carlo(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S = Array(repeating: 0.0, count: N + 1)
    S[0] = S0
    for i in 1...N {
        let z = Double.random(in: -1...1) * sqrt(12.0)
        S[i] = S[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z)
    }
    return exp(-r * T) * max(S[N] - K, 0)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 1000
    let option_price = simulate_monte_carlo(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    print(option_price)
}

main()