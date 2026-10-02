import Foundation
import Accelerate

func monte_carlo_pricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    let d1 = (log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T))
    let d2 = d1 - sigma * sqrt(T)
    
    let call_price = S0 * exp(-r * T) * cdf_normal(d1) - K * exp(-r * T) * cdf_normal(d2)
    return call_price
}

func cdf_normal(_ x: Double) -> Double {
    return 0.5 * (1 + erf(x / sqrt(2.0)))
}

func erf(_ x: Double) -> Double {
    let a1 = 0.254829592
    let a2 = -0.284496736
    let a3 = 1.421413741
    let a4 = -1.453152027
    let a5 = 1.061405429
    let p = 0.3275911
    
    let sign = x < 0 ? -1 : 1
    let abs_x = abs(x)
    let t = 1 / (1 + p * abs_x)
    let y = 1 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-abs_x * abs_x)
    
    return sign * y
}

func main() {
    let result = monte_carlo_pricing(S0: 100, K: 100, T: 1, r: 0.05, sigma: 0.2, N: 1000, M: 100000)
    print(result)
}

main()