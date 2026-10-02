import Foundation

func simulateStockPrice(steps: Int, initialPrice: Double, drift: Double, volatility: Double) -> Double {
    var price = initialPrice
    for _ in 0..<steps {
        price += price * (drift + volatility * Double.random(in: -1...1))
    }
    return price
}

func priceOption(pricingFunction: (Int, Double, Double, Double) -> Double, initialPrice: Double, strikePrice: Double, steps: Int, drift: Double, volatility: Double, simulations: Int) -> Double {
    var total = 0.0
    for _ in 0..<simulations {
        let finalPrice = pricingFunction(steps, initialPrice, drift, volatility)
        let payoff = max(finalPrice - strikePrice, 0)
        total += payoff
    }
    return total / Double(simulations)
}

func main() {
    let initialPrice = 100.0
    let strikePrice = 100.0
    let steps = 100
    let drift = 0.0001
    let volatility = 0.01
    let simulations = 10000
    let optionPrice = priceOption(pricingFunction: simulateStockPrice, initialPrice: initialPrice, strikePrice: strikePrice, steps: steps, drift: drift, volatility: volatility, simulations: simulations)
    print("Option Price: \(optionPrice)")
}

main()