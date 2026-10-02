import Foundation

func simulate_stock_price(steps: Int, initial_price: Double, drift: Double, volatility: Double) -> [Double] {
    var prices = [initial_price]
    for _ in 0..<steps {
        let shock = Double.random(in: -1...1) // Approximating Gaussian with uniform
        let new_price = prices.last! * (1 + drift + volatility * shock)
        prices.append(new_price)
    }
    return prices
}

func option_pricing(prices: [Double], strike_price: Double, is_call: Bool) -> Double {
    var payoff = 0.0
    for price in prices {
        if is_call {
            payoff += max(0, price - strike_price)
        } else {
            payoff += max(0, strike_price - price)
        }
    }
    return payoff / Double(prices.count)
}

func main() {
    let initial_price = 100.0
    let strike_price = 105.0
    let drift = 0.01
    let volatility = 0.2
    let steps = 100
    let is_call = true
    let prices = simulate_stock_price(steps: steps, initial_price: initial_price, drift: drift, volatility: volatility)
    let value = option_pricing(prices: prices, strike_price: strike_price, is_call: is_call)
    print("Option value: \(value)")
}

main()