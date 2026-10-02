import Foundation

func simulatePrice(optionType: String, S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let dt = T / Double(N)
    let dS = S0 * (r * dt + sigma * sqrt(dt))
    var prices = [S0]
    for _ in 1...N {
        let S = prices.last! + dS * Double.random(in: -1...1)
        prices.append(S)
    }
    let payoff = optionType == "call" ? max(0, prices.last! - K) : max(0, K - prices.last!)
    return payoff
}

let S0 = 100.0
let K = 100.0
let T = 1.0
let r = 0.05
let sigma = 0.2
let N = 252
let M = 1000

var results = [Double]()
for _ in 0..<M {
    results.append(simulatePrice(optionType: "call", S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M))
}

let averagePrice = results.reduce(0, +) / Double(M)
print(averagePrice)