import Foundation

func financial_model(T: Double, N: Int, S0: Double, K: Double, r: Double, sigma: Double) -> Double {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: N + 1), count: N + 1)
    S[0][0] = S0
    for i in 1...N {
        for j in 0...i {
            S[i][j] = j > 0 ? S[i - 1][j - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1)) : 0
        }
    }
    let payoff = S[N].map { max($0 - K, 0) }
    let option_price = exp(-r * T) * payoff.reduce(0, +) / Double(N + 1)
    return option_price
}

let result = financial_model(T: 1, N: 100, S0: 100, K: 100, r: 0.05, sigma: 0.2)
print(result)