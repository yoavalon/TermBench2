import Foundation

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
        var S = Array(repeating: Array(repeating: 0.0, count: N + 1), count: M)
        for i in 0..<M {
            S[i][0] = S0
        }
        for t in 1...N {
            for i in 0..<M {
                let Z = Double.random(in: -1...1)
                S[i][t] = S[i][t - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z)
            }
        }
        return S
    }

    func calculateOptionPrice() -> Double {
        let S = simulatePaths()
        var payoff = 0.0
        for i in 0..<M {
            payoff += max(S[i][N] - K, 0)
        }
        let optionPrice = exp(-r * T) * (payoff / Double(M))
        return optionPrice
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 252
    let M = 10000
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    let price = model.calculateOptionPrice()
    print("Option price: \(String(format: "%.4f", price))")
}

main()