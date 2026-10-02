import Foundation

class FinancialModel {
    var a: Double
    var b: Double
    var c: Double
    var d: Double
    var e: Double

    init(initial_price: Double, volatility: Double, risk_free_rate: Double, strike_price: Double, maturity: Double) {
        self.a = initial_price
        self.b = volatility
        self.c = risk_free_rate
        self.d = strike_price
        self.e = maturity
    }

    func simulatePaths(n: Int) -> [[Double]] {
        var paths: [[Double]] = []
        for _ in 0..<n {
            var path: [Double] = [self.a]
            for _ in 0..<Int(self.e * 252) {
                let z = Double.random(in: 0...1)
                let s = path.last! * (1 + self.c / 252 + self.b * z / 100)
                path.append(s)
            }
            paths.append(path)
        }
        return paths
    }

    func payoff(path: [Double]) -> Double {
        return max(path.last! - self.d, 0)
    }
}

class PricingEngine {
    var f: FinancialModel

    init(model: FinancialModel) {
        self.f = model
    }

    func priceOption(simulations: Int) -> Double {
        var total = 0.0
        for _ in 0..<simulations {
            let paths = self.f.simulatePaths(n: 100)
            let payoffSum = paths.reduce(0) { $0 + self.f.payoff(path: $1) }
            total += payoffSum / Double(paths.count)
        }
        return total / Double(simulations) * pow(2.71828, -self.f.c * self.f.e)
    }
}

func main() {
    let model = FinancialModel(initial_price: 100, volatility: 20, risk_free_rate: 0.05, strike_price: 100, maturity: 1)
    let engine = PricingEngine(model: model)
    let price = engine.priceOption(simulations: 1000)
    print(price)
}

main()