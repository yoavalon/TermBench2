import Foundation

func simulatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: N + 1), count: M)
    for i in 0..<M {
        paths[i][0] = S0
    }
    for t in 1...N {
        let z = (0..<M).map { _ in Double.random(in: -1...1) }
        for i in 0..<M {
            paths[i][t] = paths[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func priceOption(paths: [[Double]], strike: Double, optionType: String) -> Double {
    var payoff = [Double]()
    for path in paths {
        if optionType == "call" {
            payoff.append(max(path.last! - strike, 0))
        } else if optionType == "put" {
            payoff.append(max(strike - path.last!, 0))
        }
    }
    return exp(-r * T) * payoff.reduce(0, +) / Double(paths.count)
}

let S0 = 100.0
let T = 1.0
let r = 0.05
let sigma = 0.2
let N = 252
let M = 10000
let strike = 100.0
let optionType = "call"

func main() {
    while true {
        let paths = simulatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
        let price = priceOption(paths: paths, strike: strike, optionType: optionType)
        print(price)
    }
}

main()