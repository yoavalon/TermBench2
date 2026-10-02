import Foundation

func simulatePrices(steps: Int, mean: Double, volatility: Double) -> [Double] {
    var prices = [Double](repeating: 0.0, count: steps)
    prices[0] = 100
    for i in 1..<steps {
        prices[i] = prices[i - 1] * (1 + Double.random(in: -volatility...volatility) + mean)
    }
    return prices
}

func calculateOptionValue(prices: [Double], strike: Double, r: Double, t: Double) -> Double {
    let payoff = max(prices.last ?? 0.0 - strike, 0.0)
    let value = payoff * exp(-r * t)
    return value
}

func main() {
    let steps = 100
    let mean = 0.001
    let volatility = 0.01
    let strike = 105.0
    let r = 0.05
    let t = 1.0
    let prices = simulatePrices(steps: steps, mean: mean, volatility: volatility)
    let optionValue = calculateOptionValue(prices: prices, strike: strike, r: r, t: t)
    print(optionValue)
}

main()