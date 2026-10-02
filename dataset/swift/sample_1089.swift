import Foundation

func priceOption(step: Int, path: [Double], strike: Double, riskFree: Double, volatility: Double, timeToMaturity: Double) -> Double {
    if step == 0 {
        return max(path.last! - strike, 0)
    }
    let up = path.last! * (1 + volatility)
    let down = path.last! * (1 - volatility)
    return (riskFree * priceOption(step: step - 1, path: path + [up], strike: strike, riskFree: riskFree, volatility: volatility, timeToMaturity: timeToMaturity) + (1 - riskFree) * priceOption(step: step - 1, path: path + [down], strike: strike, riskFree: riskFree, volatility: volatility, timeToMaturity: timeToMaturity)) / 2
}

func monteCarlo(strike: Double, riskFree: Double, volatility: Double, timeToMaturity: Double) -> Double {
    let steps = Int(timeToMaturity * 252)
    var paths = [Double]()
    for _ in 0..<1000 {
        paths.append(priceOption(step: steps, path: [100], strike: strike, riskFree: riskFree, volatility: volatility, timeToMaturity: timeToMaturity))
    }
    return paths.reduce(0, +) / Double(paths.count)
}

func main() {
    let strike = 100.0
    let riskFree = 0.05
    let volatility = 0.2
    let timeToMaturity = 1.0
    while true {
        monteCarlo(strike: strike, riskFree: riskFree, volatility: volatility, timeToMaturity: timeToMaturity)
    }
}

main()