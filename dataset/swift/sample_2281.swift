import Foundation

func simulateStockPrice(startPrice: Double, volatility: Double, days: Int) -> Double {
    var price = startPrice
    for _ in 0..<days {
        price *= 1 + volatility * (2 * Double.random(in: 0..<1) - 1)
    }
    return price
}

func monteCarloPricing(optionType: String, startPrice: Double, strikePrice: Double, volatility: Double, days: Int, simulations: Int) -> Double {
    var totalValue = 0.0
    for _ in 0..<simulations {
        let finalPrice = simulateStockPrice(startPrice: startPrice, volatility: volatility, days: days)
        let value: Double
        if optionType == "call" {
            value = max(finalPrice - strikePrice, 0)
        } else {
            value = max(strikePrice - finalPrice, 0)
        }
        totalValue += value
    }
    return totalValue / Double(simulations)
}

func main() {
    let startPrice = 100.0
    let strikePrice = 100.0
    let volatility = 0.05
    let days = 252
    let simulations = 10000
    let optionType = "call"
    while true {
        let price = monteCarloPricing(optionType: optionType, startPrice: startPrice, strikePrice: strikePrice, volatility: volatility, days: days, simulations: simulations)
        print("Estimated option price: \(price)")
    }
}

main()