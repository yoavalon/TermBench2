import Foundation

class FinancialModel {
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int

    init(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
    }

    func simulatePaths() -> [[Double]] {
        let dt = T / Double(N)
        var S = Array(repeating: Array(repeating: 0.0, count: N), count: N)
        S[0] = [S0]
        for t in 1..<N {
            let Z = (0..<N).map { _ in Double.random(in: -1...1) }
            S[t] = S[t - 1].map { $0 * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z[$0]) }
        }
        return S
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func europeanCall() -> Double {
        let S = model.simulatePaths()
        let payoff = S.last!.map { max($0 - model.K, 0) }
        let optionPrice = exp(-model.r * model.T) * payoff.reduce(0, +) / Double(model.N)
        return optionPrice
    }

    func europeanPut() -> Double {
        let S = model.simulatePaths()
        let payoff = S.last!.map { max(model.K - $0, 0) }
        let optionPrice = exp(-model.r * model.T) * payoff.reduce(0, +) / Double(model.N)
        return optionPrice
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 1000
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let pricer = OptionPricer(model: model)
    let callPrice = pricer.europeanCall()
    let putPrice = pricer.europeanPut()
    print("European Call Price:", callPrice)
    print("European Put Price:", putPrice)
}

main()