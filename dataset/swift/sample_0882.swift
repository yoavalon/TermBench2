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

    func simulatePricePaths() -> [[Double]] {
        let dt = T / Double(N)
        var paths = [[S0]]
        for _ in 1...N {
            var newPaths = [[Double]]()
            for path in paths {
                let S = path.last!
                let dW = sqrt(dt) * Double.random(in: -1...1)
                let newS = S * exp((r - 0.5 * pow(sigma, 2)) * dt + sigma * dW)
                newPaths.append(path + [newS])
            }
            paths = newPaths
        }
        return paths
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func payoff(pricePath: [Double]) -> Double {
        return max(model.K - pricePath.last!, 0)
    }

    func priceOption() -> Double {
        let paths = model.simulatePricePaths()
        let discountedPayoffs = paths.map { payoff(pricePath: $0) * exp(-model.r * model.T) }
        return discountedPayoffs.reduce(0, +) / Double(paths.count)
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let pricer = OptionPricer(model: model)
    let optionPrice = pricer.priceOption()
    print("Option Price: \(optionPrice)")
}

main()