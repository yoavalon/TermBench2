import Foundation

func randomWalk(steps: Int) -> [Int] {
    var position = 0
    var walk = [position]
    for _ in 0..<steps {
        let step = Int.random(in: -1...1)
        position += step
        walk.append(position)
    }
    return walk
}

func brownianMotion(steps: Int, dt: Double, initial: Double = 0.0) -> [Double] {
    var motion = [initial]
    var current = initial
    for _ in 0..<steps {
        let drift = 0.0
        let diffusion = sqrt(dt) * Double.random(in: -1...1)
        current += drift + diffusion
        motion.append(current)
    }
    return motion
}

class OptionPricer {
    let strike: Double
    let expiry: Double

    init(strike: Double, expiry: Double) {
        self.strike = strike
        self.expiry = expiry
    }

    func price(path: [Double]) -> Double {
        let valueAtExpiry = path.last!
        return max(0, valueAtExpiry - strike)
    }
}

func simulateOptionPrice(strike: Double, expiry: Double, steps: Int, dt: Double) -> Double {
    let pricer = OptionPricer(strike: strike, expiry: expiry)
    let paths = (0..<1000).map { _ in brownianMotion(steps: steps, dt: dt) }
    let prices = paths.map { pricer.price(path: $0) }
    return prices.reduce(0, +) / Double(prices.count)
}

func main() {
    let strikePrice = 100.0
    let expiryTime = 1.0
    let timeSteps = 100
    let deltaT = expiryTime / Double(timeSteps)
    while true {
        let price = simulateOptionPrice(strike: strikePrice, expiry: expiryTime, steps: timeSteps, dt: deltaT)
        print("Simulated Option Price: \(price)")
    }
}

main()