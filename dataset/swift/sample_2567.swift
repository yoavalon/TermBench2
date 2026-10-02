import Foundation
import Accelerate

func simulatePrices(steps: Int, simulations: Int) -> [[Double]] {
    let drift: Double = 0.05
    let volatility: Double = 0.2
    let initialPrice: Double = 100
    let dt: Double = 1.0 / Double(steps)
    var paths = Array(repeating: Array(repeating: 0.0, count: steps), count: simulations)
    for i in 0..<simulations {
        paths[i][0] = initialPrice
    }
    for t in 1..<steps {
        let z = (0..<simulations).map { _ in Double.random(in: -1...1) }
        for i in 0..<simulations {
            paths[i][t] = paths[i][t - 1] * exp((drift - 0.5 * pow(volatility, 2)) * dt + volatility * sqrt(dt) * z[i])
        }
    }
    return paths
}

func optionPricing(prices: [Double], strike: Double, optionType: String = "call") -> [Double] {
    if optionType == "call" {
        return prices.map { max($0 - strike, 0) }
    } else if optionType == "put" {
        return prices.map { max(strike - $0, 0) }
    } else {
        return []
    }
}

func main() {
    let steps = 252
    let simulations = 10000
    let strike = 105
    let prices = simulatePrices(steps: steps, simulations: simulations)
    let optionValues = optionPricing(prices: prices.map { $0.last! }, strike: strike)
    print(optionValues.reduce(0, +) / Double(optionValues.count))
}

main()