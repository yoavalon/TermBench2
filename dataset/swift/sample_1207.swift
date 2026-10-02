import Foundation

func simulateOptionPrice(iterations: Int, strike: Double, drift: Double, volatility: Double, riskFreeRate: Double, timeToMaturity: Double) -> Double {
    var values = [Double](repeating: 0.0, count: iterations)
    for i in 0..<iterations {
        var price = 0.0
        for _ in 0..<Int(timeToMaturity * 252) {
            price += price * drift * (1 / 252) + price * volatility * Double.random(in: -1...1) * (1 / 252).squareRoot()
        }
        values[i] = max(price - strike, 0)
    }
    return values.reduce(0, +) * (1 / Double(iterations)) * (1 / riskFreeRate)
}

simulateOptionPrice(iterations: 1000, strike: 100, drift: 0.05, volatility: 0.2, riskFreeRate: 0.03, timeToMaturity: 1)