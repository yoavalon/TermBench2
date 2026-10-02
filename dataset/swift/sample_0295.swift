import Foundation

class FinancialModel {
    var S0: [Double]
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int
    var dt: Double

    init(S0: [Double], K: Double, T: Double, r: Double, sigma: Double, N: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.dt = T / Double(N)
    }

    func simulate_paths() -> [[Double]] {
        var paths = Array(repeating: Array(repeating: 0.0, count: S0.count), count: N + 1)
        paths[0] = S0
        for t in 1...N {
            let z = (0..<S0.count).map { _ in Double.random(in: -1...1) }
            paths[t] = paths[t - 1].enumerated().map { (index, value) in
                value * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[index])
            }
        }
        return paths
    }

    func payoff(paths: [[Double]]) -> [Double] {
        return paths.last!.map { max($0 - K, 0) }
    }
}

class OptionPricer {
    var financial_model: FinancialModel
    var M: Int

    init(financial_model: FinancialModel, M: Int) {
        self.financial_model = financial_model
        self.M = M
    }

    func price_option() -> Double {
        var payoffs = Array(repeating: 0.0, count: M)
        for i in 0..<M {
            let paths = financial_model.simulate_paths()
            payoffs[i] = financial_model.payoff(paths: paths).reduce(0, +) / Double(financial_model.S0.count)
        }
        let option_price = exp(-financial_model.r * financial_model.T) * payoffs.reduce(0, +) / Double(M)
        return option_price
    }
}

func main() {
    let S0 = [100, 100, 100]
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let financial_model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let option_pricer = OptionPricer(financial_model: financial_model, M: M)
    print(option_pricer.price_option())
}

main()