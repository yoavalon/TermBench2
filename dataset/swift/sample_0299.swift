import Foundation

func generate_paths(S0: Double, r: Double, sigma: Double, T: Double, N: Int, M: Int) -> [[Double]] {
    var paths: [[Double]] = []
    for _ in 0..<M {
        var path = [S0]
        let dt = T / Double(N)
        for _ in 1...N {
            let z = Double.random(in: 0...1)
            let S = path.last! * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z)
            path.append(S)
        }
        paths.append(path)
    }
    return paths
}

func payoff_function(S: Double) -> Double {
    return max(S - 100, 0)
}

func monte_carlo_pricing(paths: [[Double]], payoff_function: (Double) -> Double) -> Double {
    var total_payoff = 0.0
    for path in paths {
        total_payoff += payoff_function(path.last!)
    }
    return total_payoff / Double(paths.count) * exp(-0.05 * 1)
}

func main() {
    let S0 = 100.0
    let r = 0.05
    let sigma = 0.2
    let T = 1.0
    let N = 252
    let M = 10000
    let paths = generate_paths(S0: S0, r: r, sigma: sigma, T: T, N: N, M: M)
    let option_price = monte_carlo_pricing(paths: paths, payoff_function: payoff_function)
    print("Option Price: \(option_price)")
}

main()