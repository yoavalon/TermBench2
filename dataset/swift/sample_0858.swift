import Foundation

class MonteCarlo {
    var iterations: Int
    var optionType: String
    var strike: Double
    var underlying: Double
    var sigma: Double
    var r: Double
    var t: Double

    init(iterations: Int, optionType: String, strike: Double, underlying: Double, sigma: Double, r: Double, t: Double) {
        self.iterations = iterations
        self.optionType = optionType
        self.strike = strike
        self.underlying = underlying
        self.sigma = sigma
        self.r = r
        self.t = t
    }

    func price() -> Double {
        var total = 0.0
        for _ in 0..<iterations {
            let price = underlying * exp(r * t + sigma * sqrt(t) * Double.random(in: -1...1))
            let payoff = payoff(price)
            let discountedPayoff = payoff * exp(-r * t)
            total += discountedPayoff
        }
        return total / Double(iterations)
    }

    func payoff(_ price: Double) -> Double {
        if optionType == "call" {
            return max(price - strike, 0)
        } else if optionType == "put" {
            return max(strike - price, 0)
        }
        return 0
    }
}

class Option {
    var type: String
    var strike: Double
    var underlying: Double
    var sigma: Double
    var r: Double
    var t: Double

    init(type: String, strike: Double, underlying: Double, sigma: Double, r: Double, t: Double) {
        self.type = type
        self.strike = strike
        self.underlying = underlying
        self.sigma = sigma
        self.r = r
        self.t = t
    }

    func evaluate() -> Double {
        let model = MonteCarlo(iterations: 10000, optionType: type, strike: strike, underlying: underlying, sigma: sigma, r: r, t: t)
        return model.price()
    }
}

func main() {
    let option = Option(type: "call", strike: 100, underlying: 100, sigma: 0.2, r: 0.05, t: 1)
    let result = option.evaluate()
    print("Option price: \(result)")
}

main()