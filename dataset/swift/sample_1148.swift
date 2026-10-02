import Foundation

class OptionPricer {
    var S: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int
    var M: Int

    init(S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) {
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.M = M
    }

    func simulate_stock_prices() -> [[Double]] {
        let dt = T / Double(N)
        var paths = [[S]]
        for t in 1...N {
            for i in 0..<M {
                let z = Double.random(in: -1...1)
                let S_next = paths[i].last! * exp((r - 0.5 * sigma * sigma) * dt + sigma * z * sqrt(dt))
                paths[i].append(S_next)
            }
        }
        return paths
    }

    func payoff(paths: [[Double]]) -> [Double] {
        return paths.map { max($0.last! - K, 0) }
    }

    func price_option() -> Double {
        let paths = simulate_stock_prices()
        let payoffs = payoff(paths: paths)
        let C = exp(-r * T) * payoffs.reduce(0, +) / Double(M)
        return C
    }
}

func main() {
    let pricer = OptionPricer(S: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 100, M: 1000)
    while true {
        let price = pricer.price_option()
        print("Option price: \(price)")
    }
}

main()