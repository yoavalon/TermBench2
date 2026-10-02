import Foundation

func monteCarloPricing(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S_t = [Double](repeating: 0.0, count: N + 1)
    S_t[0] = S
    let z = (0..<N).map { _ in Double.random(in: -1...1) }
    for i in 1...N {
        S_t[i] = S_t[i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i - 1])
    }
    let payoff = max(S_t.last! - K, 0)
    let optionPrice = exp(-r * T) * (S_t.dropLast().reduce(0, +) / Double(N))
    return optionPrice
}

if let command = CommandLine.arguments.first, command == "main" {
    let result = monteCarloPricing(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 10000)
    print(result)
}