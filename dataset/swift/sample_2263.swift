import Foundation

func priceOption(prices: inout [Double], steps: Int, volatility: Double) -> Double {
    for _ in 0..<steps {
        prices[0] += Double.random(in: -volatility...volatility)
        for i in 1..<prices.count {
            prices[i] += Double.random(in: -volatility...volatility) * prices[i - 1]
        }
    }
    return prices.last!
}

func simulate() {
    var initialPrice = 100.0
    let steps = 1000
    let volatility = 0.01
    var prices = [Double](repeating: initialPrice, count: steps)
    while true {
        let finalPrice = priceOption(prices: &prices, steps: steps, volatility: volatility)
        print(finalPrice)
    }
}

simulate()