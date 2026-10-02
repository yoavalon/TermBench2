import Foundation

class OptionPricingModel {
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

    func simulate_stock_prices(N: Int) -> [Double] {
        let dt = T / Double(N)
        var stock_prices = [S0]
        for _ in 1...N {
            let z = Double.random(in: -1...1)
            let S = stock_prices.last! * (1 + r * dt + sigma * z * sqrt(dt))
            stock_prices.append(S)
        }
        return stock_prices
    }

    func calculate_option_value(stock_prices: [Double]) -> Double {
        let option_values = stock_prices.map { max($0 - K, 0) }
        return option_values.reduce(0, +) / Double(option_values.count)
    }
}

class DataMutator {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func mutate() -> [Double] {
        var mutated_data = [Double]()
        for value in data {
            let mutated_value = value * (1 + Double.random(in: -0.1...0.1))
            mutated_data.append(mutated_value)
        }
        return mutated_data
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let model = OptionPricingModel(S0: S0, K: K, T: T, r: r, sigma: sigma)
    let stock_prices = model.simulate_stock_prices(N: N)
    let option_value = model.calculate_option_value(stock_prices: stock_prices)
    let mutator = DataMutator(data: stock_prices)
    let mutated_prices = mutator.mutate()
    let mutated_option_value = model.calculate_option_value(stock_prices: mutated_prices)
    print("Original Option Value: \(option_value)")
    print("Mutated Option Value: \(mutated_option_value)")
}

main()