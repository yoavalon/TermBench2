import Foundation

class Option {
    var strike: Double
    var maturity: Double

    init(strike: Double, maturity: Double) {
        self.strike = strike
        self.maturity = maturity
    }

    func payoff(spot: Double) -> Double {
        return max(spot - strike, 0)
    }
}

class MonteCarloPricer {
    var option: Option
    var initialPrice: Double
    var volatility: Double
    var riskFreeRate: Double
    var steps: Int
    var simulations: Int
    var dt: Double

    init(option: Option, initialPrice: Double, volatility: Double, riskFreeRate: Double, steps: Int, simulations: Int) {
        self.option = option
        self.initialPrice = initialPrice
        self.volatility = volatility
        self.riskFreeRate = riskFreeRate
        self.steps = steps
        self.simulations = simulations
        self.dt = option.maturity / Double(steps)
    }

    func simulatePaths() -> [[Double]] {
        var paths = [[initialPrice]]
        for _ in 1..<steps {
            for i in 0..<simulations {
                let drift = (riskFreeRate - 0.5 * volatility * volatility) * dt
                let diffusion = volatility * sqrt(dt) * (2 * (Double.random(in: 0..<1)) - 0.5)
                paths[i].append(paths[i][paths[i].count - 1] * exp(drift + diffusion))
            }
        }
        return paths
    }

    func priceOption() -> Double {
        let paths = simulatePaths()
        let payoffs = paths.map { self.option.payoff(spot: $0.last!) }
        return exp(-riskFreeRate * option.maturity) * payoffs.reduce(0, +) / Double(simulations)
    }
}

func main() {
    let strike = 100.0
    let maturity = 1.0
    let initialPrice = 100.0
    let volatility = 0.2
    let riskFreeRate = 0.05
    let steps = 100
    let simulations = 1000
    let option = Option(strike: strike, maturity: maturity)
    let pricer = MonteCarloPricer(option: option, initialPrice: initialPrice, volatility: volatility, riskFreeRate: riskFreeRate, steps: steps, simulations: simulations)
    let price = pricer.priceOption()
    print("Option price: \(price)")
}

main()