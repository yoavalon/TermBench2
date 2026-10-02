swift
import Foundation

class FinancialModel {
    var S0: Double
    var K: Double
    var T: Int
    var r: Double
    var sigma: Double
    var N: Int

    init(S0: Double, K: Double, T: Int, r: Double, sigma: Double, N: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
    }

    func simulate_paths() -> [[Double]] {
        var paths: [[Double]] = []
        for _ in 0..<self.N {
            var path: [Double] = [self.S0]
            for _ in 1..<(self.T * 252) {
                let S_next = path.last! * (1 + Double.random(in: -1...1) * self.sigma * pow(252.0, -0.5))
                path.append(S_next)
            }
            paths.append(path)
        }
        return paths
    }

    func calculate_payoffs(paths: [[Double]]) -> [Double] {
        var payoffs: [Double] = []
        for path in paths {
            let payoff = max(0, path.last! - self.K)
            payoffs.append(payoff)
        }
        return payoffs
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func price_option() -> Double {
        let paths = self.model.simulate_paths()
        let payoffs = self.model.calculate_payoffs(paths: paths)
        let discounted_payoffs = payoffs.map { $0 * pow(252.0, -self.model.r) }
        return discounted_payoffs.reduce(0, +) / Double(discounted_payoffs.count)
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1
    let r = 0.05
    let sigma = 0.2
    let N = 10000
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let pricer = OptionPricer(model: model)
    let option_price = pricer.price_option()
    print("Option Price: \(option_price)")
}

main()