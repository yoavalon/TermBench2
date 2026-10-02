import Foundation

func monte_carlo_pricing(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(M)
    var S_t = [[Double]](repeating: [Double](repeating: 0, count: M + 1), count: N)
    
    for i in 0..<N {
        S_t[i][0] = S
    }
    
    for t in 1...M {
        for i in 0..<N {
            let z = Double.random(in: -1...1) * sqrt(12.0) // Box-Muller transform for standard normal
            S_t[i][t] = S_t[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z)
        }
    }
    
    var payoff = [Double](repeating: 0, count: N)
    for i in 0..<N {
        payoff[i] = max(S_t[i][M] - K, 0)
    }
    
    let option_price = exp(-r * T) * payoff.reduce(0, +) / Double(N)
    return option_price
}

monte_carlo_pricing(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 10000, M: 100)