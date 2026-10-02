import Foundation
import Accelerate

class FinancialModel {
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int
    var M: Int

    init(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
        self.M = M
    }

    func simulatePaths() -> [[Double]] {
        let dt = T / Double(N)
        var paths = Array(repeating: Array(repeating: 0.0, count: M + 1), count: N + 1)
        paths[0] = Array(repeating: S0, count: M + 1)
        for i in 1...N {
            let z = (0..<M).map { _ in Double.random(in: -1...1) }
            for j in 0..<M {
                paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[j])
            }
        }
        return paths
    }

    func optionPrice() -> Double {
        let paths = simulatePaths()
        let payoff = paths[N].map { max($0 - K, 0) }
        let price = exp(-r * T) * payoff.reduce(0, +) / Double(M)
        return price
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 10000
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = model.optionPrice()
    print(price)
}

main()