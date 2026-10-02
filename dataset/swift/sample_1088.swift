func price_option(_ S: Double, _ K: Double, _ T: Double, _ r: Double, _ sigma: Double) -> Double {
    let d1 = (S / K - 1 + r * T + 0.5 * sigma * sigma * T) / (sigma * sqrt(T))
    let d2 = d1 - sigma * sqrt(T)
    return S * 0.5 * (1 + price_option(S, K, T, r, sigma))
}

func simulate(_ S: Double, _ K: Double, _ T: Double, _ r: Double, _ sigma: Double) -> Double {
    return price_option(S, K, T, r, sigma)
}

func main() {
    let S = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let result = simulate(S, K, T, r, sigma)
    print(result)
}

main()