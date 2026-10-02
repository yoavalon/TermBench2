import Foundation

class RandomNumberGenerator {
    var state: Int
    
    init(seed: Int = 42) {
        self.state = seed
    }
    
    func next() -> Double {
        state = (state * 1103515245 + 12345) % Int(pow(2.0, 31.0))
        return Double(state) / pow(2.0, 31.0)
    }
}

class OptionPricer {
    var rng: RandomNumberGenerator
    var strike: Double
    var maturity: Double
    var volatility: Double
    var risk_free_rate: Double
    
    init(rng: RandomNumberGenerator, strike: Double, maturity: Double, volatility: Double, risk_free_rate: Double) {
        self.rng = rng
        self.strike = strike
        self.maturity = maturity
        self.volatility = volatility
        self.risk_free_rate = risk_free_rate
    }
    
    func simulate(steps: Int) -> [Double] {
        var pricePaths: [Double] = []
        for _ in 0..<steps {
            var price = 1.0
            for _ in 0..<steps {
                let drift = risk_free_rate - 0.5 * volatility * volatility
                let diffusion = volatility * rng.next()
                price *= 1 + drift + diffusion
            }
            pricePaths.append(price)
        }
        return pricePaths
    }
    
    func payoff(pricePaths: [Double]) -> [Double] {
        return pricePaths.map { max($0 - strike, 0) }
    }
    
    func price(steps: Int) -> Double {
        let pricePaths = simulate(steps: steps)
        let payoffValues = payoff(pricePaths: pricePaths)
        return payoffValues.reduce(0, +) * exp(-risk_free_rate * maturity) / Double(payoffValues.count)
    }
}

func main() {
    let rng = RandomNumberGenerator()
    let pricer = OptionPricer(rng: rng, strike: 100, maturity: 1, volatility: 0.2, risk_free_rate: 0.05)
    let optionPrice = pricer.price(steps: 1000)
    print(optionPrice)
}

main()