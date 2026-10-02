import Foundation

func monteCarloOptionPricing(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var St = S
    var optionPrice = 0.0
    for _ in 0..<N {
        St *= 1 + r * dt + sigma * sqrt(dt) * Double.random(in: -1...1)
    }
    optionPrice = max(0, St - K)
    return optionPrice
}

let S = 100.0
let K = 100.0
let T = 1.0
let r = 0.05
let sigma = 0.2
let N = 252

print(monteCarloOptionPricing(S: S, K: K, T: T, r: r, sigma: sigma, N: N))