import Foundation

class OptionModel {
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var n_simulations: Int

    init(S0: Double, K: Double, T: Double, r: Double, sigma: Double, n_simulations: Int) {
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.n_simulations = n_simulations
    }

    func simulate() -> [Double] {
        var option_values: [Double] = []
        for _ in 0..<n_simulations {
            let S_T = S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * Double.random(in: -1...1))
            option_values.append(max(0, S_T - K))
        }
        return option_values
    }
}

class PricingEngine {
    var model: OptionModel

    init(model: OptionModel) {
        self.model = model
    }

    func calculate_price() -> Double {
        let option_values = model.simulate()
        return option_values.reduce(0, +) / Double(option_values.count)
    }
}

class SimulationController {
    var pricing_engine: PricingEngine

    init(pricing_engine: PricingEngine) {
        self.pricing_engine = pricing_engine
    }

    func run() {
        while true {
            let price = pricing_engine.calculate_price()
            print("Option price: \(price)")
        }
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let n_simulations = 1000
    let model = OptionModel(S0: S0, K: K, T: T, r: r, sigma: sigma, n_simulations: n_simulations)
    let pricing_engine = PricingEngine(model: model)
    let controller = SimulationController(pricing_engine: pricing_engine)
    controller.run()
}

main()