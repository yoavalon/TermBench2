import Foundation

func simulatePaths(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = Array(repeating: Array(repeating: 0.0, count: M), count: N + 1)
    paths[0] = Array(repeating: S0, count: M)
    for i in 1...N {
        let Z = (0..<M).map { _ in Double.random(in: -1...1) }
        paths[i] = paths[i - 1].enumerated().map { $0.element * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[$0.offset]) }
    }
    return paths
}

func calculatePayoffs(paths: [[Double]], K: Double, T: Double, r: Double, M: Int) -> Double {
    let S_T = paths.last!
    let payoff = S_T.map { max($0 - K, 0) }
    let optionValue = exp(-r * T) * payoff.reduce(0, +) / Double(M)
    return optionValue
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 252
    let M = 100000
    while true {
        let paths = simulatePaths(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
        let optionValue = calculatePayoffs(paths: paths, K: K, T: T, r: r, M: M)
        print(optionValue)
    }
}

main()