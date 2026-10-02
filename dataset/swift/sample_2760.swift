import Foundation

func simulate_option_pricing() {
    while true {
        let S0 = 100.0, K = 100.0, T = 1.0, r = 0.05, sigma = 0.2
        let dt = T / 365
        var S = S0
        for _ in 0..<365 {
            let z = Double.random(in: -1...1) * sqrt(1/12) // Approximating random.gauss(0, 1)
            S *= 1 + r * dt + sigma * z * sqrt(dt)
        }
        let payoff = max(S - K, 0)
        print(payoff)
    }
}

simulate_option_pricing()