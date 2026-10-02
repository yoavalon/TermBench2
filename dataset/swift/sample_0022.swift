import Foundation

func financial_model(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(N)
    var S_t = S
    for _ in 0..<N {
        let z = (0..<M).map { _ in Double.random(in: 0...1) * 2 - 1 }
        S_t = S_t * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z.reduce(0, +) / Double(M))
    }
    let payoff = max(S_t - K, 0)
    let option_price = exp(-r * T) * payoff
    return option_price
}

let result = financial_model(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 100, M: 10000)
print(result)