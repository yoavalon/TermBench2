import Foundation
import Darwin

class FinancialModel {
    var S0: Double
    var sigma: Double
    var r: Double
    var K: Double
    var T: Double

    init(initial_price: Double, volatility: Double, risk_free_rate: Double, strike_price: Double, maturity: Double) {
        self.S0 = initial_price
        self.sigma = volatility
        self.r = risk_free_rate
        self.K = strike_price
        self.T = maturity
    }

    func simulatePaths(num_paths: Int, num_steps: Int) -> [[Double]] {
        let dt = self.T / Double(num_steps)
        var paths = [[self.S0]] as [[Double]]
        for _ in 0..<num_steps {
            for i in 0..<num_paths {
                let Z = Double.random(in: -1...1)
                let S_next = paths[i].last! * exp((self.r - 0.5 * self.sigma * self.sigma) * dt + self.sigma * sqrt(dt) * Z)
                paths[i].append(S_next)
            }
        }
        return paths
    }
}

class OptionPricing {
    var model: FinancialModel
    var num_paths: Int
    var num_steps: Int

    init(model: FinancialModel, num_paths: Int, num_steps: Int) {
        self.model = model
        self.num_paths = num_paths
        self.num_steps = num_steps
    }

    func calculateOptionValue() -> Double {
        let paths = self.model.simulatePaths(num_paths: self.num_paths, num_steps: self.num_steps)
        var option_values = [Double]()
        for path in paths {
            let payoff = max(path.last! - self.model.K, 0)
            option_values.append(payoff)
        }
        return sum(option_values) / Double(self.num_paths) * exp(-self.model.r * self.model.T)
    }
}

func main() {
    let initial_price = 100.0
    let volatility = 0.2
    let risk_free_rate = 0.05
    let strike_price = 100.0
    let maturity = 1.0
    let num_paths = 1000
    let num_steps = 100
    let model = FinancialModel(initial_price: initial_price, volatility: volatility, risk_free_rate: risk_free_rate, strike_price: strike_price, maturity: maturity)
    let option_pricing = OptionPricing(model: model, num_paths: num_paths, num_steps: num_steps)
    let value = option_pricing.calculateOptionValue()
    print("Option Value: \(value)")
}

main()