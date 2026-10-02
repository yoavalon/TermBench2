import Foundation

class OptionPricing {
    
    var S: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    
    init(S: Double, K: Double, T: Double, r: Double, sigma: Double) {
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
    }
    
    func calculate_price(n_simulations: Int, depth: Int) -> Double {
        if depth == 0 {
            return black_scholes(S: S, K: K, T: T, r: r, sigma: sigma)
        } else {
            return monte_carlo(n_simulations: n_simulations, depth: depth)
        }
    }
    
    func black_scholes(S: Double, K: Double, T: Double, r: Double, sigma: Double) -> Double {
        let d1 = (log(S / K) + (r + 0.5 * pow(sigma, 2)) * T) / (sigma * sqrt(T))
        let d2 = d1 - sigma * sqrt(T)
        return S * exp(-r * T) * norm_cdf(x: d1) - K * exp(-r * T) * norm_cdf(x: d2)
    }
    
    func norm_cdf(x: Double) -> Double {
        return (1.0 + erf(x / sqrt(2.0))) / 2.0
    }
    
    func monte_carlo(n_simulations: Int, depth: Int) -> Double {
        var payoff_sum = 0.0
        for _ in 0..<n_simulations {
            let price_path = price_path_simulation()
            payoff_sum += max(price_path.last! - K, 0)
        }
        return payoff_sum / Double(n_simulations) * exp(-r * T)
    }
    
    func price_path_simulation() -> [Double] {
        var path = [S]
        for _ in 0..<Int(T) {
            let drift = r * path.last! * (1 / 252)
            let diffusion = path.last! * sigma * sqrt(1 / 252) * Double.random(in: -1...1)
            path.append(path.last! + drift + diffusion)
        }
        return path
    }
}

func main() {
    let S = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let n_simulations = 1000
    let depth = 2
    let pricing_model = OptionPricing(S: S, K: K, T: T, r: r, sigma: sigma)
    let option_price = pricing_model.calculate_price(n_simulations: n_simulations, depth: depth)
    print("Option Price: \(option_price)")
}

main()