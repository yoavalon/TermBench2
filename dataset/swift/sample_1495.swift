import Foundation

class OptionPricer {
    var S: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double

    init(S: Double, K: Double, T: Double, r: Double, sigma: Double) {
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
    }

    func d1() -> Double {
        return (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T))
    }

    func d2() -> Double {
        return d1() - sigma * sqrt(T)
    }

    func call_price() -> Double {
        return S * exp(-r * T) * cdf(d1()) - K * exp(-r * T) * cdf(d2())
    }

    func put_price() -> Double {
        return K * exp(-r * T) * cdf(-d2()) - S * exp(-r * T) * cdf(-d1())
    }

    func cdf(_ x: Double) -> Double {
        return 0.5 * (1 + erf(x / sqrt(2)))
    }
}

class MonteCarloSimulator {
    var pricer: OptionPricer
    var simulations: Int

    init(pricer: OptionPricer, simulations: Int) {
        self.pricer = pricer
        self.simulations = simulations
    }

    func simulate() -> (Double, Double) {
        var call_values = [Double]()
        var put_values = [Double]()
        for _ in 0..<simulations {
            let S_T = pricer.S * exp((pricer.r - 0.5 * pricer.sigma * pricer.sigma) * pricer.T + pricer.sigma * sqrt(pricer.T) * Double.random(in: -1...1))
            call_values.append(max(S_T - pricer.K, 0))
            put_values.append(max(pricer.K - S_T, 0))
        }
        return (call_values.reduce(0, +) / Double(simulations), put_values.reduce(0, +) / Double(simulations))
    }
}

func main() {
    let S = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let simulations = 10000
    let pricer = OptionPricer(S: S, K: K, T: T, r: r, sigma: sigma)
    let simulator = MonteCarloSimulator(pricer: pricer, simulations: simulations)
    let (call_price, put_price) = simulator.simulate()
    print("Call Price: \(call_price)")
    print("Put Price: \(put_price)")
}

main()