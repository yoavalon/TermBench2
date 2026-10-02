import Foundation

func generatePaths(S0: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    paths[0] = Array(repeating: S0, count: M)
    for t in 1...N {
        let z = (0..<M).map { _ in Double.random(in: -1...1) }
        for i in 0..<M {
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[i])
        }
    }
    return paths
}

func calculatePayoffs(paths: [[Double]], K: Double, optionType: String) -> [Double]? {
    if optionType == "call" {
        return paths.last!.map { max($0 - K, 0) }
    } else if optionType == "put" {
        return paths.last!.map { max(K - $0, 0) }
    }
    return nil
}

func priceOption(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int, optionType: String) -> Double {
    let paths = generatePaths(S0: S0, T: T, r: r, sigma: sigma, N: N, M: M)
    if let payoffs = calculatePayoffs(paths: paths, K: K, optionType: optionType) {
        return exp(-r * T) * payoffs.reduce(0, +) / Double(M)
    }
    return 0.0
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let optionType = "call"
    let optionPrice = priceOption(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M, optionType: optionType)
    print("Option price: \(String(format: "%.2f", optionPrice))")
}

main()