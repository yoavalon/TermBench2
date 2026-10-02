import Foundation

func monte_carlo_price(s: Double, k: Double, r: Double, t: Double, v: Double, n: Int, simulations: Int) -> Double {
    func simulate() -> Double {
        var price = s
        for _ in 0..<n {
            let z = sqrt(-2 * log(Double.random(in: 0..<1))) * cos(2 * .pi * Double.random(in: 0..<1))
            price *= 1 + (r - v * v / 2) + v * z
        }
        return max(price - k, 0)
    }
    var total = 0.0
    for _ in 0..<simulations {
        total += simulate()
    }
    return total / Double(simulations)
}

monte_carlo_price(s: 100, k: 100, r: 0.05, t: 1, v: 0.2, n: 252, simulations: 10000)