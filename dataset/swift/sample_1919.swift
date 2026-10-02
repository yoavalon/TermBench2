import Foundation

func generatePaths(S0: Double, r: Double, sigma: Double, T: Double, M: Int, N: Int) -> [[Double]] {
    let dt = T / Double(M)
    var paths = Array(repeating: Array(repeating: 0.0, count: N), count: M + 1)
    paths[0] = Array(repeating: S0, count: N)
    for t in 1...M {
        let z = (0..<N).map { _ in Double.random(in: -1...1) * sqrt(12) }
        paths[t] = paths[t - 1].enumerated().map { $0.element * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[$0.offset]) }
    }
    return paths
}

func priceOption(paths: [[Double]], strike: Double, T: Double, r: Double) -> Double {
    let payoff = paths.last!.map { max($0 - strike, 0) }
    return exp(-r * T) * payoff.reduce(0, +) / Double(payoff.count)
}

func main() {
    let S0: Double = 100
    let r: Double = 0.05
    let sigma: Double = 0.2
    let T: Double = 1
    let M: Int = 100
    let N: Int = 1000
    let K: Double = 100
    let paths = generatePaths(S0: S0, r: r, sigma: sigma, T: T, M: M, N: N)
    let optionPrice = priceOption(paths: paths, strike: K, T: T, r: r)
    print("Option Price: \(optionPrice)")
}

main()