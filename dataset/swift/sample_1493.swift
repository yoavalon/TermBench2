import Foundation

class OptionPricer {
    var S0: [Double]
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int

    init(S0: [Double], K: Double, T: Double, r: Double, sigma: Double, N: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
    }

    func simulatePaths() -> [[Double]] {
        let dt = T / Double(N)
        var paths = Array(repeating: Array(repeating: 0.0, count: S0.count), count: N + 1)
        paths[0] = S0
        for i in 1...N {
            let z = S0.map { _ in Double.random(in: -1...1) }
            paths[i] = paths[i - 1].enumerated().map { (index, value) in
                value * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[index])
            }
        }
        return paths
    }

    func calculatePayoff(paths: [[Double]]) -> [Double] {
        return paths.last!.map { max($0 - K, 0) }
    }
}

class MonteCarloEngine {
    var pricer: OptionPricer
    var num_simulations: Int

    init(pricer: OptionPricer, num_simulations: Int) {
        self.pricer = pricer
        self.num_simulations = num_simulations
    }

    func run() -> Double {
        var payoffs = Array(repeating: 0.0, count: num_simulations)
        for i in 0..<num_simulations {
            let paths = pricer.simulatePaths()
            payoffs[i] = pricer.calculatePayoff(paths: paths).reduce(0, +) / Double(paths[0].count)
        }
        let price = exp(-pricer.r * pricer.T) * payoffs.reduce(0, +) / Double(num_simulations)
        return price
    }
}

func main() {
    let S0 = [100.0]
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 252
    let num_simulations = 10000
    let pricer = OptionPricer(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let engine = MonteCarloEngine(pricer: pricer, num_simulations: num_simulations)
    let optionPrice = engine.run()
    print("Option Price: \(optionPrice)")
}

main()