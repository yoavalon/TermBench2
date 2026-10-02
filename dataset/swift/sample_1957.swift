import Foundation

func simulate_prices(steps: Int, simulations: Int) -> [[Double]] {
    var prices = Array(repeating: Array(repeating: 0.0, count: simulations), count: steps)
    for i in 0..<steps {
        for j in 0..<simulations {
            prices[i][j] = Double.random(in: 0.05...0.2)
        }
    }
    return prices
}

func calculate_option_value(prices: [[Double]], strike: Double) -> Double {
    let final_prices = prices.last!
    let values = final_prices.map { max($0 - strike, 0) }
    return values.reduce(0, +) / Double(values.count)
}

func main() {
    let steps = 100
    let simulations = 1000
    let strike = 100.0
    let prices = simulate_prices(steps: steps, simulations: simulations)
    let value = calculate_option_value(prices: prices, strike: strike)
    print(value)
}

main()