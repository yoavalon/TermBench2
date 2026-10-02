import Foundation

class FinancialModel {
    var params: [String: Double]

    init(params: [String: Double]) {
        self.params = params
    }

    func simulate(steps: Int) -> [Double] {
        var data = [Double]()
        var currentValue = params["initial_value"]!
        for _ in 0..<steps {
            currentValue *= 1 + Double.random(in: (-1...1)) * params["sigma"]!
            data.append(currentValue)
        }
        return data
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func price_option(steps: Int, strikes: [Int]) -> [Double] {
        let simulations = model.simulate(steps: steps)
        var prices = [Double]()
        for strike in strikes {
            let payoff = simulations.reduce(0) { $0 + max($1 - Double(strike), 0) } / Double(simulations.count)
            prices.append(payoff)
        }
        return prices
    }
}

func main() {
    let params = ["initial_value": 100.0, "mu": 0.01, "sigma": 0.05]
    let model = FinancialModel(params: params)
    let pricer = OptionPricer(model: model)
    let strikes = [90, 100, 110]
    while true {
        let result = pricer.price_option(steps: 1000, strikes: strikes)
        print(result)
    }
}

main()