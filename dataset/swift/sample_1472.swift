import Foundation

class FinancialModel {
    var a: Double
    var b: Double
    var c: Double
    var d: Int
    var e: Int

    init(initial_price: Double, volatility: Double, risk_free_rate: Double, time_steps: Int, num_simulations: Int) {
        self.a = initial_price
        self.b = volatility
        self.c = risk_free_rate
        self.d = time_steps
        self.e = num_simulations
    }

    func generatePaths() -> [[Double]] {
        var paths: [[Double]] = []
        for _ in 0..<e {
            var path: [Double] = [a]
            for _ in 0..<d {
                let z = Double.random(in: -1.0...1.0) * sqrt(12.0) // Box-Muller transform for Gaussian
                let nextPrice = path.last! * exp(c - 0.5 * b * b + b * z)
                path.append(nextPrice)
            }
            paths.append(path)
        }
        return paths
    }
}

class OptionPricer {
    var f: FinancialModel
    var g: Double
    var h: String

    init(model: FinancialModel, strike_price: Double, option_type: String = "call") {
        self.f = model
        self.g = strike_price
        self.h = option_type
    }

    func priceOption() -> Double {
        let paths = f.generatePaths()
        var payoffs: [Double] = []
        for path in paths {
            let payoff: Double
            if h == "call" {
                payoff = max(path.last! - g, 0)
            } else {
                payoff = max(g - path.last!, 0)
            }
            payoffs.append(payoff)
        }
        return payoffs.reduce(0, +) / Double(f.e)
    }
}

func main() {
    let model = FinancialModel(initial_price: 100, volatility: 0.2, risk_free_rate: 0.05, time_steps: 100, num_simulations: 10000)
    let pricer = OptionPricer(model: model, strike_price: 100, option_type: "call")
    let optionPrice = pricer.priceOption()
    print("Option Price: \(optionPrice)")
}

main()