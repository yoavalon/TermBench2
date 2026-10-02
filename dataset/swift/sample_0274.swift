import Foundation

func generatePaths(S0: Double, mu: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    let dt = T / Double(N)
    var paths = [[S0]](repeating: [S0], count: M)
    for _ in 1...N {
        for j in 0..<M {
            let z = Double.random(in: 0...1)
            let S = paths[j].last! * (1 + mu * dt + sigma * z * sqrt(dt))
            paths[j].append(S)
        }
    }
    return paths
}

func payoff(paths: [[Double]], K: Double, T: Double) -> [Double] {
    let terminalValues = paths.map { $0.last! }
    return terminalValues.map { max($0 - K, 0) }
}

func discount(payoffs: [Double], r: Double, T: Double) -> [Double] {
    return payoffs.map { $0 / pow(1 + r, T) }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let r = 0.05
    let T = 1.0
    let N = 252
    let M = 10000
    let mu = 0.05
    let sigma = 0.2
    let paths = generatePaths(S0: S0, mu: mu, sigma: sigma, T: T, N: N, M: M)
    let payoffs = payoff(paths: paths, K: K, T: T)
    let discountedPayoffs = discount(payoffs: payoffs, r: r, T: T)
    let optionPrice = discountedPayoffs.reduce(0, +) / Double(M)
    print("Option Price:", optionPrice)
}

main()