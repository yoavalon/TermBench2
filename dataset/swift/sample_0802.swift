import Foundation

class MonteCarlo {
    var price: Double
    var strike: Double
    var rate: Double
    var volatility: Double
    var time: Double
    var simulations: Int

    init(price: Double, strike: Double, rate: Double, volatility: Double, time: Double, simulations: Int) {
        self.price = price
        self.strike = strike
        self.rate = rate
        self.volatility = volatility
        self.time = time
        self.simulations = simulations
    }

    func _simulate(count: Int) -> [Double] {
        if count >= simulations {
            return []
        }
        let dt = time / Double(simulations)
        let drift = (rate - 0.5 * volatility * volatility) * dt
        let diffusion = volatility * sqrt(dt)
        let price = self.price * exp(drift + diffusion * Double.random(in: -1...1))
        return [price] + _simulate(count: count + 1)
    }

    func _payoff(prices: [Double]) -> [Double] {
        return prices.map { max($0 - strike, 0) }
    }

    func price_option() -> Double {
        let prices = _simulate(count: 0)
        let payoffs = _payoff(prices: prices)
        return exp(-rate * time) * payoffs.reduce(0, +) / Double(simulations)
    }
}

func main() {
    let price = 100.0
    let strike = 100.0
    let rate = 0.05
    let volatility = 0.2
    let time = 1.0
    let simulations = 10000
    let model = MonteCarlo(price: price, strike: strike, rate: rate, volatility: volatility, time: time, simulations: simulations)
    print(model.price_option())
}

main()