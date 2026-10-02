swift
import Foundation

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S = [Double](repeating: 0.0, count: N + 1)
    S[0] = S0
    for t in 1...N {
        S[t] = S[t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
    }
    return exp(-r * T) * max(S[N] - K, 0)
}

func main() {
    while true {
        let result = monte_carlo_pricing(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 252)
        print(result)
    }
}

main()