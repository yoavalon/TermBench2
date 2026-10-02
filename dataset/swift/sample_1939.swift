import Foundation

func simulateStockPrices(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: N + 1), count: M)
    for i in 0..<M {
        S[i][0] = S0
    }
    for t in 1...N {
        let Z = (0..<M).map { _ in Double.random(in: -1...1) }
        for i in 0..<M {
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[i])
        }
    }
    return S
}

func priceEuropeanOption(S: [[Double]], K: Double, T: Double, r: Double) -> Double {
    let payoff = S.map { max($0.last! - K, 0) }
    let meanPayoff = payoff.reduce(0, +) / Double(payoff.count)
    return exp(-r * T) * meanPayoff
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 100000
    let S = simulateStockPrices(S0: S0, mu: r, sigma: sigma, T: T, N: N, M: M)
    let optionPrice = priceEuropeanOption(S: S, K: K, T: T, r: r)
    print(optionPrice)
}

main()