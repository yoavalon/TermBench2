import Foundation

func simulatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: N), count: M)
    for i in 0..<M {
        S[i][0] = S0
    }
    for t in 1..<N {
        let z = Array(repeating: Double.random(in: -1.0...1.0), count: M).map { sqrt(-2.0 * log($0)) * cos(2.0 * .pi * Double.random(in: 0.0...1.0)) }
        for i in 0..<M {
            S[i][t] = S[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return S
}

func calculateOptionPrice(paths: [[Double]], K: Double, r: Double, T: Double) -> Double {
    let payoff = paths.map { max($0.last! - K, 0) }
    let optionPrice = exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
    return optionPrice
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 252
    let M = 10000
    let paths = simulatePaths(S0: S0, mu: r, sigma: 0.2, T: T, N: N, M: M)
    let optionPrice = calculateOptionPrice(paths: paths, K: K, r: r, T: T)
    print(optionPrice)
}

main()