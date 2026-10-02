import Foundation

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(M)
    var S = Array(repeating: Array(repeating: 0.0, count: N), count: M + 1)
    S[0] = Array(repeating: S0, count: N)
    
    for t in 1...M {
        let Z = (0..<N).map { _ in Double.random(in: -1...1) }
        for i in 0..<N {
            S[t][i] = S[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[i])
        }
    }
    
    let payoff = S[M].map { max($0 - K, 0) }
    let meanPayoff = payoff.reduce(0, +) / Double(N)
    return exp(-r * T) * meanPayoff
}

monte_carlo_pricing(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 10000, M: 100)