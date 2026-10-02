import Foundation

class OptionPricing {
    var a: Double
    var b: Double
    var c: Double
    var d: Double
    var e: Double

    init(strike: Double, volatility: Double, riskFreeRate: Double, timeToMaturity: Double, initialPrice: Double) {
        self.a = strike
        self.b = volatility
        self.c = riskFreeRate
        self.d = timeToMaturity
        self.e = initialPrice
    }

    func simulatePaths(steps: Int, simulations: Int) -> [[Double]] {
        var paths = [[e]]
        for _ in 0..<steps {
            var newPaths = [[Double]]()
            for path in paths {
                let lastPrice = path.last!
                let drift = (c - 0.5 * b * b) * d
                let diffusion = b * lastPrice * Double.random(in: -1...1)
                let newPrice = lastPrice * exp(drift + diffusion)
                newPaths.append(path + [newPrice])
            }
            paths = newPaths
        }
        return paths
    }

    func calculatePayoff(paths: [[Double]]) -> [Double] {
        var payoff = [Double]()
        for path in paths {
            let finalPrice = path.last!
            payoff.append(max(0, finalPrice - a))
        }
        return payoff
    }
}

class DataMutator {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func mutate() -> [Double] {
        var mutatedData = [Double]()
        for item in data {
            mutatedData.append(item * (1 + Double.random(in: -0.05...0.05)))
        }
        return mutatedData
    }
}

func main() {
    let option = OptionPricing(strike: 100, volatility: 0.2, riskFreeRate: 0.05, timeToMaturity: 1, initialPrice: 100)
    let paths = option.simulatePaths(steps: 100, simulations: 1000)
    let payoff = option.calculatePayoff(paths: paths)
    let mutator = DataMutator(data: payoff)
    let mutatedPayoff = mutator.mutate()
    print(mutatedPayoff)
}

main()