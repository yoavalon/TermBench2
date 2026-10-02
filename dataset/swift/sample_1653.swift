import Foundation

func simulate_stock_price(S0: Double, mu: Double, sigma: Double, T: Double, dt: Double) -> Double {
    var S = S0
    for _ in 0..<Int(T / dt) {
        let dS = mu * S * dt + sigma * S * Double.random(in: -1...1) * sqrt(dt)
        S += dS
    }
    return S
}

func monte_carlo_option_price(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, dt: Double) -> Double {
    var option_price = 0.0
    for _ in 0..<N {
        let S_T = simulate_stock_price(S0: S0, mu: r, sigma: sigma, T: T, dt: dt)
        option_price += max(S_T - K, 0)
    }
    return option_price * (1.0 / Double(N)) * exp(-r * T)
}

func main() {
    let S0 = 100.0, K = 100.0, T = 1.0, r = 0.05, sigma = 0.2, N = 100000, dt = 0.01
    let price = monte_carlo_option_price(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, dt: dt)
    print("Option Price: \(price)")
}

main()