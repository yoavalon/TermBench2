swift
import Foundation

func financial_model(S0: Double, K: Double, T: Double, r: Double, sigma: Double) -> Double {
    let N = 10000
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: N + 1), count: N + 1)
    S[0][0] = S0
    for t in 1...N {
        for i in 0...t {
            let Z = Double.random(in: -1...1)
            S[t][i] = S[t - 1][i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z)
        }
    }
    let optionValues = S[N].compactMap { $0 - K > 0 ? $0 - K : nil }
    return optionValues.reduce(0, +) / Double(optionValues.count)
}

func main() {
    print(financial_model(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2))
}

main()