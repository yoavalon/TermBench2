import Foundation

func simulate_options(num_simulations: Int, strike_price: Double, underlying_price: Double, volatility: Double, risk_free_rate: Double, time_to_maturity: Double) -> Double {
    var values: [Double] = []
    for _ in 0..<num_simulations {
        let z = Double.random(in: -1...1)
        let value = max(0, underlying_price * exp((risk_free_rate - 0.5 * volatility * volatility) * time_to_maturity + volatility * sqrt(time_to_maturity) * z) - strike_price)
        values.append(value)
    }
    return values.reduce(0, +) / Double(num_simulations)
}

simulate_options(num_simulations: 1000, strike_price: 100, underlying_price: 100, volatility: 0.2, risk_free_rate: 0.05, time_to_maturity: 1)