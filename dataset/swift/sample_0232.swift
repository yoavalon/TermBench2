import Foundation

func generatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    var paths = [[Double]](repeating: [S0], count: M)
    let dt = T / Double(N)
    for i in 1...N {
        for j in 0..<M {
            let Z = Double.random(in: 0...1)
            let S = paths[j].last! * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z)
            paths[j].append(S)
        }
    }
    return paths
}

func payoffFunction(S: Double, K: Double, optionType: String) -> Double {
    if optionType == "call" {
        return max(S - K, 0)
    } else if optionType == "put" {
        return max(K - S, 0)
    }
    return 0
}

func monteCarloPricing(paths: [[Double]], K: Double, r: Double, T: Double, optionType: String) -> Double {
    let payoffs = paths.map { payoffFunction(S: $0.last!, K: K, optionType: optionType) }
    let presentValue = exp(-r * T) * payoffs.reduce(0, +) / Double(payoffs.count)
    return presentValue
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 100
    let M = 10000
    let optionType = "call"
    let paths = generatePaths(S0: S0, mu: r, sigma: 0.2, T: T, N: N, M: M)
    let price = monteCarloPricing(paths: paths, K: K, r: r, T: T, optionType: optionType)
    print("Option price: \(price)")
}

main()