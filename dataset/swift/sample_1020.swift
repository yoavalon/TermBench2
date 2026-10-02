import Foundation

func simulate_price(initial_price: Double, volatility: Double, time_steps: Int) -> [Double] {
    var prices = [initial_price]
    for _ in 0..<time_steps {
        let drift = 0.05 * prices.last!
        let shock = volatility * prices.last! * Double.random(in: -1...1)
        let new_price = prices.last! + drift + shock
        prices.append(new_price)
    }
    return prices
}

func calculate_option_price(prices: [Double], strike_price: Double, option_type: String = "call") -> Double {
    if option_type == "call" {
        return max(0, max(prices) - strike_price)
    } else {
        return max(0, strike_price - min(prices))
    }
}

func main() {
    let initial_price = 100.0
    let volatility = 0.2
    let time_steps = 100
    let strike_price = 105.0
    while true {
        let prices = simulate_price(initial_price: initial_price, volatility: volatility, time_steps: time_steps)
        let option_price = calculate_option_price(prices: prices, strike_price: strike_price)
        print("Option price: \(option_price)")
    }
}

main()