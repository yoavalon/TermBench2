import Foundation

class DataMutation {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func applyMutation(mutationFunction: ([Double]) -> [Double]) -> [Double] {
        self.data = mutationFunction(self.data)
        return self.data
    }
}

class FinancialModel {
    var initialPrice: Double
    var volatility: Double
    var riskFreeRate: Double
    var timeSteps: Int
    var simulations: Int

    init(initialPrice: Double, volatility: Double, riskFreeRate: Double, timeSteps: Int, simulations: Int) {
        self.initialPrice = initialPrice
        self.volatility = volatility
        self.riskFreeRate = riskFreeRate
        self.timeSteps = timeSteps
        self.simulations = simulations
    }

    func simulatePaths() -> [[Double]] {
        let dt = 1.0 / Double(timeSteps)
        let drift = (riskFreeRate - 0.5 * volatility * volatility) * dt
        let diffusion = volatility * sqrt(dt)
        var paths = Array(repeating: Array(repeating: 0.0, count: simulations), count: timeSteps + 1)
        paths[0] = Array(repeating: initialPrice, count: simulations)
        for t in 1...timeSteps {
            let rand = (0..<simulations).map { _ in Double.random(in: -1...1) }
            paths[t] = paths[t - 1].enumerated().map { paths[t - 1][$0] * exp(drift + diffusion * rand[$0]) }
        }
        return paths
    }

    func calculatePayoff(strikePrice: Double, optionType: String = "call") -> [Double] {
        let paths = simulatePaths()
        if optionType == "call" {
            return paths.last!.map { max($0 - strikePrice, 0) }
        } else {
            return paths.last!.map { max(strikePrice - $0, 0) }
        }
    }

    func priceOption(strikePrice: Double, optionType: String = "call") -> Double {
        let payoff = calculatePayoff(strikePrice: strikePrice, optionType: optionType)
        let optionPrice = exp(-riskFreeRate * Double(timeSteps)) * payoff.reduce(0, +) / Double(simulations)
        return optionPrice
    }
}

func main() {
    let data = (0..<100).map { _ in Double.random(in: 0...1) }
    let dataMutator = DataMutation(data: data)
    let mutatedData = dataMutator.applyMutation { $0.map { $0 * 2 } }
    let financialModel = FinancialModel(initialPrice: mutatedData[0], volatility: 0.2, riskFreeRate: 0.05, timeSteps: 252, simulations: 10000)
    let optionPrice = financialModel.priceOption(strikePrice: 100, optionType: "call")
    print(optionPrice)
}

main()