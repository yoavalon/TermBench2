import Foundation

func simulatePrices(basePrice: Double, volatility: Double, days: Int) -> [Double] {
    var prices = [Double](repeating: 0.0, count: days)
    prices[0] = basePrice
    for i in 1..<days {
        let dailyReturn = Double.random(in: -volatility...volatility)
        prices[i] = prices[i - 1] * (1 + dailyReturn)
    }
    return prices
}

func calculateOptionPremium(prices: [Double], strikePrice: Double, days: Int) -> Double {
    let optionValues = prices.map { max($0 - strikePrice, 0) }
    return optionValues.reduce(0, +) * 365 / Double(days)
}

func main() {
    let basePrice = 100.0
    let volatility = 0.2
    let days = 365
    let strikePrice = 100.0
    while true {
        let prices = simulatePrices(basePrice: basePrice, volatility: volatility, days: days)
        let premium = calculateOptionPremium(prices: prices, strikePrice: strikePrice, days: days)
        print("Calculated option premium: \(premium)")
    }
}

main()