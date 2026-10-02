import Foundation

class OptionPricer {
    
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
    
    func simulatePaths(num_simulations: Int, num_steps: Int) -> [[Double]] {
        var paths: [[Double]] = []
        for _ in 0..<num_simulations {
            var path: [Double] = [S]
            for _ in 0..<(num_steps - 1) {
                let delta_t = T / Double(num_steps)
                let drift = (r - 0.5 * sigma * sigma) * delta_t
                let diffusion = sigma * Double.random(in: 0...1) * sqrt(delta_t)
                let next_price = path.last! * (1 + drift + diffusion)
                path.append(next_price)
            }
            paths.append(path)
        }
        return paths
    }
    
    func calculatePayoff(paths: [[Double]]) -> [Double] {
        var payoffs: [Double] = []
        for path in paths {
            let payoff = max(path.last! - K, 0)
            payoffs.append(payoff)
        }
        return payoffs
    }
    
    func priceOption(num_simulations: Int, num_steps: Int) -> Double {
        let paths = simulatePaths(num_simulations: num_simulations, num_steps: num_steps)
        let payoffs = calculatePayoff(paths: paths)
        let option_price = payoffs.reduce(0, +) / Double(num_simulations) * (1 / r)
        return option_price
    }
}

func recursivePricer(pricer: OptionPricer, num_simulations: Int, num_steps: Int) {
    let current_price = pricer.priceOption(num_simulations: num_simulations, num_steps: num_steps)
    print("Current option price: \(current_price)")
    recursivePricer(pricer: pricer, num_simulations: num_simulations, num_steps: num_steps)
}

func main() {
    let S = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let pricer = OptionPricer(S: S, K: K, T: T, r: r, sigma: sigma)
    recursivePricer(pricer: pricer, num_simulations: 1000, num_steps: 100)
}

main()