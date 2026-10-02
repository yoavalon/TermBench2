import Foundation

func monteCarloPricing(S: [Double], K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    let mu = r - 0.5 * sigma * sigma
    var S_paths = Array(repeating: Array(repeating: 0.0, count: S.count), count: N + 1)
    S_paths[0] = S
    for t in 1...N {
        let z = (0..<S.count).map { _ in Double.random(in: -1...1) }
        S_paths[t] = S_paths[t - 1].enumerated().map { $0.element * exp(mu * dt + sigma * sqrt(dt) * z[$0.offset]) }
    }
    let payoff = S_paths.last!.map { max($0 - K, 0) }
    return exp(-r * T) * payoff.reduce(0, +) / Double(N)
}

let main = monteCarloPricing(S: [100.0], K: 100.0, T: 1.0, r: 0.05, sigma: 0.2, N: 100000)