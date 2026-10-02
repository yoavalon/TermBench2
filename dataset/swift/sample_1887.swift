import Foundation

func monte_carlo_option_pricing(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S_T = [Double]()
    
    for _ in 0..<N {
        let z = Double.random(in: -1...1)
        let S_Ti = S * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z)
        S_T.append(S_Ti)
    }
    
    let payoff = S_T.map { max($0 - K, 0) }
    let payoff_mean = payoff.reduce(0, +) / Double(N)
    
    return exp(-r * T) * payoff_mean
}

if #available(macOS 10.15, *) {
    let result = monte_carlo_option_pricing(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 10000)
    print(result)
}