swift
import Foundation

func simulate_stock_price(s0: Double, mu: Double, sigma: Double, dt: Double) -> Double {
    return s0 * (1 + mu * dt + sigma * Double.random(in: -1...1) * dt ** 0.5)
}

func monte_carlo_option_pricing(s0: Double, strike: Double, r: Double, t: Double, sigma: Double, n_simulations: Int) -> Double {
    let dt = t / 252
    var option_values: [Double] = []
    for _ in 0..<n_simulations {
        var price = s0
        for _ in 0..<252 {
            price = simulate_stock_price(s0: price, mu: r - 0.5 * sigma ** 2, sigma: sigma, dt: dt)
        }
        option_values.append(max(price - strike, 0))
    }
    return option_values.reduce(0, +) / Double(n_simulations)
}

func main() {
    let s0 = 100.0, strike = 105.0, r = 0.05, t = 1.0, sigma = 0.2, n_simulations = 10000
    while true {
        let price = monte_carlo_option_pricing(s0: s0, strike: strike, r: r, t: t, sigma: sigma, n_simulations: n_simulations)
        print("Option price: \(price)")
    }
}

main()