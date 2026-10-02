import Foundation

class OptionPricing {
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

    func _simulate_paths(S0: Double, T: Double, r: Double, sigma: Double, N: Int) -> [Double] {
        let dt = T / Double(N)
        var paths = [S0]
        for _ in 1...N {
            let z = Double.random(in: -1...1)
            let S = paths.last! * (1 + r * dt + sigma * z * sqrt(dt))
            paths.append(S)
        }
        return paths
    }

    func _option_value(paths: [Double], K: Double) -> Double {
        var value = 0.0
        for S_T in paths {
            value += max(S_T - K, 0)
        }
        return value / Double(paths.count)
    }

    func price() -> Double {
        let paths = _simulate_paths(S0: S0, T: T, r: r, sigma: sigma, N: N)
        return _option_value(paths: paths, K: K)
    }
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 1000
    let option = OptionPricing(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N)
    let result = option.price()
    print("Option price: \(result)")
}

main()