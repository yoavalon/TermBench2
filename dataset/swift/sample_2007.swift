import Foundation

class FinancialModel {
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double

    init(S0: Double, K: Double, T: Double, r: Double, sigma: Double) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
    }

    func simulatePaths(num_simulations: Int, num_steps: Int) -> [[Double]] {
        var paths = [[Double]]()
        let dt = T / Double(num_steps)
        for _ in 0..<num_simulations {
            var S = S0
            var path = [S]
            for _ in 0..<num_steps {
                let dS = S * (r * dt + sigma * sqrt(dt) * Double.random(in: -1...1))
                S += dS
                path.append(S)
            }
            paths.append(path)
        }
        return paths
    }
}

class OptionPricer {
    var model: FinancialModel

    init(model: FinancialModel) {
        self.model = model
    }

    func europeanCallPrice(paths: [[Double]]) -> Double {
        var payoff = 0.0
        for path in paths {
            payoff += max(path.last! - model.K, 0)
        }
        payoff /= Double(paths.count)
        let discountFactor = exp(-model.r * model.T)
        return payoff * discountFactor
    }
}

class AnalysisEngine {
    var pricer: OptionPricer

    init(pricer: OptionPricer) {
        self.pricer = pricer
    }

    func execute(num_simulations: Int, num_steps: Int) -> Double {
        let paths = pricer.model.simulatePaths(num_simulations: num_simulations, num_steps: num_steps)
        let price = pricer.europeanCallPrice(paths: paths)
        return price
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let num_simulations = 1000
    let num_steps = 100
    let model = FinancialModel(S0: S0, K: K, T: T, r: r, sigma: sigma)
    let pricer = OptionPricer(model: model)
    let engine = AnalysisEngine(pricer: pricer)
    let price = engine.execute(num_simulations: num_simulations, num_steps: num_steps)
    print("European Call Option Price: \(price)")
}

main()