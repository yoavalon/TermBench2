import Foundation

func simulateGeometricBrownianMotion(S0: Double, mu: Double, sigma: Double, T: Double, N: Int) -> Double {
    let dt = T / Double(N)
    var S = [S0]
    for i in 1...N {
        let dS = S[i - 1] * (mu * dt + sigma * Double.random(in: 0...1).squareRoot())
        S.append(S[i - 1] + dS)
    }
    return S.last!
}

func monteCarloOptionPricing(S0: Double, K: Double, T: Double, r: Double, sigma: Double, N: Int, M: Int) -> Double {
    var C = 0.0
    for _ in 0..<M {
        let ST = simulateGeometricBrownianMotion(S0: S0, mu: r, sigma: sigma, T: T, N: N)
        C += max(ST - K, 0)
    }
    return C / Double(M)
}

func main() {
    let S0 = 100.0
    let K = 100.0
    let T = 1.0
    let r = 0.05
    let sigma = 0.2
    let N = 100
    let M = 1000
    let optionPrice = monteCarloOptionPricing(S0: S0, K: K, T: T, r: r, sigma: sigma, N: N, M: M)
    print(optionPrice)
}

main()