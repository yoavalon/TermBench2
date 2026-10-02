import Foundation

func monteCarloOptionPricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S = [Double](repeating: 0, count: N + 1)
    S[0] = S0
    for i in 1...N {
        S[i] = S[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
    }
    let payoff = max(S[N] - K, 0)
    let optionPrice = exp(-r * T) * payoff
    return optionPrice
}

if CommandLine.arguments.count > 0 {
    let result = monteCarloOptionPricing(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 1000)
    print(result)
}