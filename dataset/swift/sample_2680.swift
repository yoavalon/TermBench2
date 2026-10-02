import Foundation

func generatePrices(numDays: Int, initialPrice: Double, volatility: Double) -> [Double] {
    var prices = [initialPrice]
    for _ in 0..<numDays - 1 {
        let change = Double.random(in: 0...1) * 2 - 1
        let newPrice = prices.last! * (1 + change * volatility)
        prices.append(newPrice)
    }
    return prices
}

func calculatePayoffs(prices: [Double], strikePrice: Double, callOrPut: String) -> [Double] {
    var payoffs = [Double]()
    for price in prices {
        if callOrPut == "call" {
            let payoff = max(price - strikePrice, 0)
            payoffs.append(payoff)
        } else {
            let payoff = max(strikePrice - price, 0)
            payoffs.append(payoff)
        }
    }
    return payoffs
}

func monteCarloPricing(numSimulations: Int, numDays: Int, initialPrice: Double, strikePrice: Double, volatility: Double, callOrPut: String, riskFreeRate: Double, timeToMaturity: Double) -> Double {
    var totalPayoff = 0.0
    for _ in 0..<numSimulations {
        let prices = generatePrices(numDays: numDays, initialPrice: initialPrice, volatility: volatility)
        let payoffs = calculatePayoffs(prices: prices, strikePrice: strikePrice, callOrPut: callOrPut)
        let discountedPayoff = payoffs.reduce(0, +) / Double(payoffs.count) * pow(1 + riskFreeRate, -timeToMaturity)
        totalPayoff += discountedPayoff
    }
    return totalPayoff / Double(numSimulations)
}

func main() {
    let numSimulations = 1000
    let numDays = 365
    let initialPrice = 100.0
    let strikePrice = 100.0
    let volatility = 0.2
    let callOrPut = "call"
    let riskFreeRate = 0.05
    let timeToMaturity = 1.0
    let optionPrice = monteCarloPricing(numSimulations: numSimulations, numDays: numDays, initialPrice: initialPrice, strikePrice: strikePrice, volatility: volatility, callOrPut: callOrPut, riskFreeRate: riskFreeRate, timeToMaturity: timeToMaturity)
    print("Option price: \(optionPrice)")
}

main()