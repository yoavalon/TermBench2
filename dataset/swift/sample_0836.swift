import Foundation

class FinancialModel {
    var price: Double
    var strike: Double
    var volatility: Double
    var rate: Double
    var time: Double

    init(price: Double, strike: Double, volatility: Double, rate: Double, time: Double) {
        self.price = price
        self.strike = strike
        self.volatility = volatility
        self.rate = rate
        self.time = time
    }

    func d1() -> Double {
        return (log(price / strike) + (rate + 0.5 * pow(volatility, 2)) * time) / (volatility * sqrt(time))
    }

    func d2() -> Double {
        return d1() - volatility * sqrt(time)
    }

    func call_price() -> Double {
        return price * exp(-rate * time) * cdf(d1()) - strike * exp(-rate * time) * cdf(d2())
    }

    func put_price() -> Double {
        return strike * exp(-rate * time) * cdf(-d2()) - price * exp(-rate * time) * cdf(-d1())
    }

    func cdf(_ x: Double) -> Double {
        return 0.5 * (1 + erf(x / sqrt(2)))
    }
}

func simulate_pricing(model: FinancialModel, simulations: Int, depth: Int) -> Double {
    if depth == 0 {
        return 0
    }
    let call_value = model.call_price()
    let put_value = model.put_price()
    return call_value + put_value + simulate_pricing(model: model, simulations: simulations, depth: depth - 1)
}

func main() {
    let model = FinancialModel(price: 100, strike: 100, volatility: 0.2, rate: 0.05, time: 1)
    let simulations = 1000
    let depth = 5
    let total_value = simulate_pricing(model: model, simulations: simulations, depth: depth)
    print("Total Estimated Value: \(total_value)")
}

main()