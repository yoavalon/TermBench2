import Foundation

func generatePaths(s0: Double, mu: Double, sigma: Double, dt: Double, T: Double, N: Int) -> [[Double]] {
    var paths = Array(repeating: Array(repeating: 0.0, count: Int(T / dt) + 1), count: N)
    for i in 0..<N {
        paths[i][0] = s0
    }
    for t in 1...Int(T / dt) {
        let z = (0..<N).map { _ in Double.random(in: -1...1) * sqrt(12) }
        for i in 0..<N {
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func calculatePayoff(paths: [[Double]], strike: Double, optionType: String) -> [Double]? {
    if optionType == "call" {
        return paths.map { max($0.last! - strike, 0) }
    } else if optionType == "put" {
        return paths.map { max(strike - $0.last!, 0) }
    }
    return nil
}

func monteCarloPricing(s0: Double, strike: Double, r: Double, T: Double, sigma: Double, N: Int, dt: Double, optionType: String) -> Double {
    let paths = generatePaths(s0: s0, mu: r, sigma: sigma, dt: dt, T: T, N: N)
    if let payoff = calculatePayoff(paths: paths, strike: strike, optionType: optionType) {
        let discountFactor = exp(-r * T)
        let optionPrice = discountFactor * payoff.reduce(0, +) / Double(N)
        return optionPrice
    }
    return 0.0
}

func main() {
    let s0 = 100.0
    let strike = 100.0
    let r = 0.05
    let T = 1.0
    let sigma = 0.2
    let N = 10000
    let dt = 0.01
    let optionType = "call"
    let price = monteCarloPricing(s0: s0, strike: strike, r: r, T: T, sigma: sigma, N: N, dt: dt, optionType: optionType)
    print(price)
}

main()