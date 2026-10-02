import Foundation

func simulateStockPrice(start: Double, volatility: Double, days: Int) -> [Double] {
    var prices = [start]
    for _ in 0..<days {
        let priceChange = Double.random(in: -volatility...volatility)
        let newPrice = prices.last! * (1 + priceChange)
        prices.append(newPrice)
    }
    return prices
}

func calculateOptionValue(prices: [Double], strike: Double, days: Int, riskFreeRate: Double) -> Double {
    let finalPrice = prices.last!
    let payoff = max(finalPrice - strike, 0)
    return payoff / pow(1 + riskFreeRate, Double(days))
}

func main() {
    let startPrice = 100.0
    let volatility = 0.2
    let strikePrice = 105.0
    let days = 30
    let riskFreeRate = 0.05
    let iterations = 1000
    var totalValue = 0.0
    for _ in 0..<iterations {
        let prices = simulateStockPrice(start: startPrice, volatility: volatility, days: days)
        let optionValue = calculateOptionValue(prices: prices, strike: strikePrice, days: days, riskFreeRate: riskFreeRate)
        totalValue += optionValue
    }
    let averageValue = totalValue / Double(iterations)
    print(averageValue)
}

main()