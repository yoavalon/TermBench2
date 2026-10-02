import Foundation

func calculate_price(option_type: String, S: Double, K: Double, T: Double, r: Double, sigma: Double, n: Int) -> Double {
    if n == 0 {
        if option_type == "call" {
            return max(S - K, 0)
        } else {
            return max(K - S, 0)
        }
    } else {
        let d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T))
        let d2 = d1 - sigma * sqrt(T)
        if option_type == "call" {
            return S * exp(-r * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2)
        } else {
            return K * exp(-r * T) * norm_cdf(-d2) - S * exp(-r * T) * norm_cdf(-d1)
        }
    }
}

func norm_cdf(x: Double) -> Double {
    return 0.5 * (1 + erf(x / sqrt(2)))
}

func monte_carlo_simulation(option_type: String, S: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, n: Int) -> Double {
    var total_price = 0.0
    for _ in 0..<N {
        var S_T = S
        for _ in 0..<n {
            let z = Double.random(in: -1...1)
            S_T *= exp((r - 0.5 * sigma * sigma) * T / Double(n) + sigma * sqrt(T / Double(n)) * z)
        }
        total_price += calculate_price(option_type: option_type, S: S_T, K: K, T: T, r: r, sigma: sigma, n: 0)
    }
    return total_price / Double(N)
}

func main() {
    let S = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 10000
    let n = 10
    let option_type = "call"
    let result = monte_carlo_simulation(option_type: option_type, S: S, K: K, T: T, r: r, sigma: sigma, N: N, n: n)
    print(result)
}

main()