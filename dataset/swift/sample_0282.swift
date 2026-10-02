import Foundation

class FinancialModel {
    var s0: Double
    var k: Double
    var t: Double
    var r: Double
    var sigma: Double
    var n_simulations: Int

    init(s0: Double, k: Double, t: Double, r: Double, sigma: Double, n_simulations: Int) {
        self.s0 = s0
        self.k = k
        self.t = t
        self.r = r
        self.sigma = sigma
        self.n_simulations = n_simulations
    }

    func simulate_paths() -> [[Double]] {
        let dt = t / 365.0
        var paths = Array(repeating: Array(repeating: 0.0, count: 365), count: n_simulations)
        for i in 0..<n_simulations {
            paths[i][0] = s0
        }
        for i in 1..<365 {
            let z = (0..<n_simulations).map { _ in Double.random(in: -1...1) }
            for j in 0..<n_simulations {
                paths[j][i] = paths[j][i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[j])
            }
        }
        return paths
    }

    func calculate_payoff(paths: [[Double]]) -> [Double] {
        let payoff = paths.map { max($0.last! - k, 0) }
        return payoff
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func price_option() -> Double {
        let paths = model.simulate_paths()
        let payoff = model.calculate_payoff(paths: paths)
        let option_price = exp(-model.r * model.t) * payoff.reduce(0, +) / Double(model.n_simulations)
        return option_price
    }
}

func main() {
    let s0 = 100.0
    let k = 100.0
    let t = 1.0
    let r = 0.05
    let sigma = 0.2
    let n_simulations = 10000
    let model = FinancialModel(s0: s0, k: k, t: t, r: r, sigma: sigma, n_simulations: n_simulations)
    let pricer = OptionPricer(model: model)
    let price = pricer.price_option()
    print(price)
}

main()