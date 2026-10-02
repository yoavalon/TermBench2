import Foundation

class RandomGenerator {
    var seed: UInt32

    init(seed: UInt32) {
        self.seed = seed
    }

    func generate() -> Double {
        seed = (1664525 * seed + 1013904223) % 4294967296
        return Double(seed) / 4294967296.0
    }
}

class OptionPricer {
    var random_gen: RandomGenerator
    var S0: Double
    var K: Double
    var T: Double
    var r: Double
    var sigma: Double
    var N: Int

    init(random_gen: RandomGenerator, S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int) {
        self.random_gen = random_gen
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N
    }

    func simulate_paths() -> [[Double]] {
        var paths: [[Double]] = []
        let dt = T / Double(N)
        for _ in 0..<1000 {
            var S = S0
            var path: [Double] = [S]
            for _ in 0..<N {
                let Z = random_gen.generate()
                S += S * r * dt + S * sigma * sqrt(dt) * (2 * Z - 1)
                path.append(S)
            }
            paths.append(path)
        }
        return paths
    }

    func price() -> Double {
        let paths = simulate_paths()
        var payoff_sum = 0.0
        for path in paths {
            let payoff = max(path.last ?? 0, 0)
            payoff_sum += payoff
        }
        return exp(-r * T) * (payoff_sum / Double(paths.count))
    }
}

func main() {
    let seed: UInt32 = 12345
    let random_gen = RandomGenerator(seed: seed)
    let pricer = OptionPricer(random_gen: random_gen, S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 100)
    let option_price = pricer.price()
    print("Option Price: \(option_price)")
}

main()