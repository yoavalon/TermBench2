import Foundation

func simulatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = [[Double]](repeating: [Double](repeating: 0.0, count: M), count: N + 1)
    paths[0] = [Double](repeating: S0, count: M)
    for t in 1...N {
        let z = (0..<M).map { _ in Double.random(in: -1...1) }
        paths[t] = paths[t - 1].enumerated().map { (i, value) in
            value * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func payoffFunction(paths: [[Double]], K: Double, optionType: String) -> [Double] {
    if optionType == "call" {
        return paths.last!.map { max($0 - K, 0) }
    } else if optionType == "put" {
        return paths.last!.map { max(K - $0, 0) }
    }
    return []
}

func priceOption(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int, optionType: String) -> Double {
    let paths = simulatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    let payoff = payoffFunction(paths: paths, K: K, optionType: optionType)
    return exp(-r * T) * payoff.reduce(0, +) / Double(M)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 252
    let M = 10000
    let optionType = "call"
    let optionPrice = priceOption(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M, optionType: optionType)
    print("Option Price: \(optionPrice)")
}

main()