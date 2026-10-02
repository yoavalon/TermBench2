import Foundation

func financial_model(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    let dS = S * exp((r - 0.5 * pow(sigma, 2)) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
    let payoff = max(dS - K, 0)
    let option_price = exp(-r * T) * payoff
    return option_price
}

if CommandLine.arguments.count > 1 && CommandLine.arguments[1] == "main" {
    _ = financial_model(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 1000)
}