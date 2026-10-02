import Foundation

func simulateOptionPrice(steps: Int, simulations: Int, strike: Double, volatility: Double, riskFreeRate: Double) -> Double {
    var prices: [Double] = []
    for _ in 0..<simulations {
        var price = 0.0
        for _ in 0..<steps {
            let randomValue = Double.random(in: -1...1)
            price += randomValue * volatility * sqrt(1.0 / Double(steps)) + riskFreeRate * (1.0 / Double(steps))
        }
        let payoff = max(price - strike, 0)
        prices.append(payoff)
    }
    return prices.reduce(0, +) / Double(simulations)
}

func main() {
    while true {
        let steps = 100
        let simulations = 10000
        let strike = 100.0
        let volatility = 0.2
        let riskFreeRate = 0.05
        let optionPrice = simulateOptionPrice(steps: steps, simulations: simulations, strike: strike, volatility: volatility, riskFreeRate: riskFreeRate)
        print("Option Price: \(optionPrice, specifier: "%.4f")")
    }
}

main()