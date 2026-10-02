import Foundation
import Accelerate

class OptionPricer {
    var strike: Double
    var spot: Double
    var vol: Double
    var rate: Double
    var div: Double
    var T: Double

    init(strike: Double, spot: Double, vol: Double, rate: Double, div: Double, T: Double) {
        self.strike = strike
        self.spot = spot
        self.vol = vol
        self.rate = rate
        self.div = div
        self.T = T
    }

    func d1(S: Double, K: Double, T: Double, r: Double, q: Double, sigma: Double) -> Double {
        return (log(S / K) + (r - q + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T))
    }

    func d2(d1: Double, sigma: Double, T: Double) -> Double {
        return d1 - sigma * sqrt(T)
    }

    func call_price(S: Double, K: Double, T: Double, r: Double, q: Double, sigma: Double) -> Double {
        if T <= 0 {
            return max(0, S - K)
        }
        let d1_val = d1(S: S, K: K, T: T, r: r, q: q, sigma: sigma)
        let d2_val = d2(d1: d1_val, sigma: sigma, T: T)
        return S * exp(-q * T) * normCDF(x: d1_val) - K * exp(-r * T) * normCDF(x: d2_val)
    }
}

class MonteCarloSimulator {
    var pricer: OptionPricer
    var paths: Int
    var steps: Int

    init(pricer: OptionPricer, paths: Int, steps: Int) {
        self.pricer = pricer
        self.paths = paths
        self.steps = steps
    }

    func simulate() -> [Double] {
        var prices = [Double]()
        for _ in 0..<paths {
            var pricePath = pricer.spot
            for _ in 1..<steps {
                pricePath = _step(S: pricePath)
            }
            prices.append(pricePath)
        }
        return prices
    }

    func _step(S: Double) -> Double {
        let dt = pricer.T / Double(steps)
        let dS = S * (pricer.rate - pricer.div) * dt + S * pricer.vol * sqrt(dt) * sqrt(drand48())
        return S + dS
    }
}

func normCDF(x: Double) -> Double {
    let a1 = 0.254829592
    let a2 = -0.284496736
    let a3 = 1.421413741
    let a4 = -1.453152027
    let a5 = 1.061405429
    let p = 0.3275911
    let t = 1.0 / (1.0 + p * x)
    let y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x)
    return x > 0.0 ? y : 1.0 - y
}

func main() {
    let strike = 100.0
    let spot = 100.0
    let vol = 0.2
    let rate = 0.05
    let div = 0.02
    let T = 1.0
    let paths = 1000
    let steps = 100
    let pricer = OptionPricer(strike: strike, spot: spot, vol: vol, rate: rate, div: div, T: T)
    let simulator = MonteCarloSimulator(pricer: pricer, paths: paths, steps: steps)
    let finalPrices = simulator.simulate()
    let optionValue = finalPrices.map { pricer.call_price(S: $0, K: strike, T: T, r: rate, q: div, sigma: vol) }.reduce(0, +) / Double(paths)
    print(optionValue)
}

main()