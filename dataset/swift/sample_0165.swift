import Foundation

func generatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var S = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    S[0] = Array(repeating: S0, count: M)
    for t in 1...N {
        for m in 0..<M {
            S[t][m] = S[t - 1][m] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
        }
    }
    return S
}

func optionPrice(paths: [[Double]], K: Double, r: Double, T: Double, payoff: ([Double], Double) -> Double) -> Double {
    let discountedPayoffs = paths.last!.map { payoff([$0], K) }
    return discountedPayoffs.reduce(0, +) / Double(discountedPayoffs.count)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 252
    let M = 10000
    let sigma = 0.2
    let mu = 0.1

    func europeanCall(S: [Double], K: Double) -> Double {
        return max(S.first! - K, 0)
    }

    let paths = generatePaths(S0: S0, mu: mu, sigma: sigma, T: T, N: N, M: M)
    let callPrice = optionPrice(paths: paths, K: K, r: r, T: T, payoff: europeanCall)
    print(callPrice)
}

main()