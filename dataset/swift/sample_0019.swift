import Foundation

func calculate_option_price(S: Double, K: Double, r: Double, T: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    let dS = S * sigma * sqrt(dt)
    var paths: [Double] = []
    for _ in 0..<N {
        paths.append(S * exp((r - 0.5 * sigma * sigma) * dt + dS * Double.random(in: -1...1)))
    }
    let payoff = paths.last! - K > 0 ? paths.last! - K : 0
    return exp(-r * T) * payoff
}

if CommandLine.arguments.count == 1 {
    let result = calculate_option_price(S: 100, K: 100, r: 0.05, T: 1, sigma: 0.2, N: 1000)
    print(result)
}