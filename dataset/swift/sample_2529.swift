import Foundation

func simulatePriceChanges(steps: Int, initialPrice: Double, volatility: Double) -> [Double] {
    var prices = [initialPrice]
    for _ in 0..<steps {
        let change = Double.random(in: -volatility...volatility)
        prices.append(prices.last! * exp(change))
    }
    return prices
}

func calculateOptionValue(prices: [Double], strike: Double, r: Double, T: Double) -> Double {
    var value = 0.0
    for price in prices {
        value += max(price - strike, 0) * exp(-r * T)
    }
    return value / Double(prices.count)
}

func main() {
    let initialPrice = 100.0
    let strike = 105.0
    let r = 0.05
    let T = 1.0
    let volatility = 0.2
    let steps = 1000
    let prices = simulatePriceChanges(steps: steps, initialPrice: initialPrice, volatility: volatility)
    let optionValue = calculateOptionValue(prices: prices, strike: strike, r: r, T: T)
    print("Option Value: \(optionValue)")
}

main()