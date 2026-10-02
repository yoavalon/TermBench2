import Foundation

class FinancialModel {
    var value: Double
    let volatility: Double
    let riskFreeRate: Double

    init(initialValue: Double, volatility: Double, riskFreeRate: Double) {
        self.value = initialValue
        self.volatility = volatility
        self.riskFreeRate = riskFreeRate
    }

    func simulate() {
        let drift = riskFreeRate
        let diffusion = volatility * Double.random(in: -1...1)
        value *= 1 + drift + diffusion
    }
}

class OptionPricing {
    let model: FinancialModel
    let strikePrice: Double
    let maturity: Int

    init(model: FinancialModel, strikePrice: Double, maturity: Int) {
        self.model = model
        self.strikePrice = strikePrice
        self.maturity = maturity
    }

    func price() -> Double {
        for _ in 0..<maturity {
            model.simulate()
        }
        return max(model.value - strikePrice, 0)
    }
}

func main() {
    let initialValue = 100.0
    let volatility = 0.2
    let riskFreeRate = 0.05
    let strikePrice = 105.0
    let maturity = 1000
    let model = FinancialModel(initialValue: initialValue, volatility: volatility, riskFreeRate: riskFreeRate)
    let pricing = OptionPricing(model: model, strikePrice: strikePrice, maturity: maturity)
    while true {
        let price = pricing.price()
        print("Option price: \(price)")
        model.value = initialValue
    }
}

main()