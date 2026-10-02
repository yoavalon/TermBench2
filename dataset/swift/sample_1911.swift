import Foundation

func simulatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    S[0] = Array(repeating: S0, count: M)
    for t in 1...N {
        let Z = (0..<M).map { _ in Double.random(in: -1...1) }
        for i in 0..<M {
            S[t][i] = S[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[i])
        }
    }
    return S
}

func optionPrice(S: [[Double]], K: Double, T: Double, r: Double, type: String = "call") -> Double {
    let payoff = S.last!.map { type == "call" ? max($0 - K, 0) : max(K - $0, 0) }
    let price = exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
    return price
}

func main() {
    let S0 = 100.0, K = 100.0, T = 1.0, r = 0.05, sigma = 0.2
    let N = 100, M = 10000
    let S = simulatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = optionPrice(S: S, K: K, T: T, r: r)
    print(price)
}

main()