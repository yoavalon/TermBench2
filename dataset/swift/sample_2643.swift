import Foundation

class FinancialModel {
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int

    init(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
    }

    func simulate_paths() -> [[Double]] {
        let dt = T / Double(N)
        var paths = [[S0]]
        for _ in 0..<N {
            var new_paths = [[Double]]()
            for path in paths {
                let S = path.last!
                let Z = Double.random(in: -1...1) * sqrt(12.0)
                let S_new = S * exp((r - 0.5 * sigma * sigma) * dt + sigma * Z * sqrt(dt))
                new_paths.append(path + [S_new])
            }
            paths = new_paths
        }
        return paths
    }

    func calculate_payoff(paths: [[Double]]) -> [Double] {
        var payoffs = [Double]()
        for path in paths {
            let ST = path.last!
            let payoff = max(0, ST - K)
            payoffs.append(payoff)
        }
        return payoffs
    }
}

class PricingEngine {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func price_option() -> Double {
        let paths = model.simulate_paths()
        let payoffs = model.calculate_payoff(paths: paths)
        let discounted_payoffs = payoffs.map { $0 * exp(-model.r * model.T) }
        let option_price = discounted_payoffs.reduce(0, +) / Double(discounted_payoffs.count)
        return option_price
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let engine = PricingEngine(model: model)
    let price = engine.price_option()
    print(price)
}

main()