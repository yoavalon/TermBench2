import Foundation

func simulate_stock_price(days: Int, initial_price: Double, volatility: Double) -> [Double] {
    var price = initial_price
    var prices = [price]
    for _ in 0..<days {
        price *= 1 + volatility * Double.random(in: -1...1)
        prices.append(price)
    }
    return prices
}

func calculate_option_value(prices: [Double], strike_price: Double, days: Int, risk_free_rate: Double) -> Double {
    let final_price = prices.last!
    let payoff = max(final_price - strike_price, 0)
    let discount_factor = 1 / pow(1 + risk_free_rate, Double(days))
    return payoff * discount_factor
}

func main() {
    let days = 30
    let initial_price = 100.0
    let volatility = 0.2
    let strike_price = 105.0
    let risk_free_rate = 0.05
    let prices = simulate_stock_price(days: days, initial_price: initial_price, volatility: volatility)
    let option_value = calculate_option_value(prices: prices, strike_price: strike_price, days: days, risk_free_rate: risk_free_rate)
    print("Option value: \(option_value)")
}

main()