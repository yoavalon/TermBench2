import Foundation

func run_model(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(N)
    var ST = [[Double]](repeating: [Double](repeating: 0.0, count: N), count: M)
    
    for i in 0..<M {
        for j in 0..<N {
            ST[i][j] = S * pow(M_E, (r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
        }
    }
    
    for i in 0..<M {
        for j in 1..<N {
            ST[i][j] += ST[i][j - 1]
        }
    }
    
    for i in 0..<M {
        ST[i].insert(S, at: 0)
    }
    
    var payoff = [Double](repeating: 0.0, count: M)
    for i in 0..<M {
        payoff[i] = max(ST[i][N] - K, 0)
    }
    
    let option_price = exp(-r * T) * payoff.reduce(0, +) / Double(M)
    return option_price
}

run_model(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 252, M: 10000)