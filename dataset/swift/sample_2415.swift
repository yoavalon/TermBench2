import Foundation

func simulate_option_price(S0: Double, K: Double, T: Double, r: Double, sigma: Double, steps: Int, trials: Int) -> Double {
    let dt = T / Double(steps)
    var dW = [[Double]](repeating: [Double](repeating: 0.0, count: trials), count: steps)
    var S = [[Double]](repeating: [Double](repeating: S0, count: trials), count: steps)
    
    for i in 0..<steps {
        for j in 0..<trials {
            dW[i][j] = Double.random(in: -1...1) * sqrt(dt)
            if i > 0 {
                S[i][j] = S[i-1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * dW[i][j])
            }
        }
    }
    
    let payoff = S[steps-1].map { max($0 - K, 0.0) }
    let payoffMean = payoff.reduce(0, +) / Double(trials)
    return exp(-r * T) * payoffMean
}

simulate_option_price(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, steps: 100, trials: 1000)