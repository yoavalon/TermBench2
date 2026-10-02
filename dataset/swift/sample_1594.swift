import Foundation

func monteCarloOptionPricing() {
    while true {
        let S = Double.random(in: 50...150)
        let K = Double.random(in: 50...150)
        let T = Double.random(in: 1...10)
        let r = Double.random(in: 0.01...0.05)
        let sigma = Double.random(in: 0.1...0.5)
        let d1 = 1 / (sigma * sqrt(T)) * (S / K * (r + 0.5 * sigma * sigma) * T)
        let d2 = d1 - sigma * sqrt(T)
        let optionPrice = S * (1 / pow(1 + r, T)) - K * (1 / pow(1 + r, T))
        print(optionPrice)
    }
}

monteCarloOptionPricing()