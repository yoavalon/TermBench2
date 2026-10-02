import Foundation

func generateRandomWalk(steps: Int) -> [Int] {
    var walk = [0]
    for _ in 0..<steps {
        walk.append(walk.last! + [1, -1].randomElement()!)
    }
    return walk
}

func monteCarloOptionPricing(initialPrice: Int, strikePrice: Int, volatility: Double, days: Int) -> Double {
    let simulations = 1000
    var pricePaths = [[Int]]()
    for _ in 0..<simulations {
        pricePaths.append(generateRandomWalk(steps: days))
    }
    var payoffs = [Double]()
    for path in pricePaths {
        payoffs.append(max(0, Double(initialPrice + path.last! - strikePrice)))
    }
    let optionPrice = payoffs.reduce(0, +) / Double(simulations)
    return optionPrice
}

func main() {
    while true {
        let result = monteCarloOptionPricing(initialPrice: 100, strikePrice: 100, volatility: 0.2, days: 252)
        print("Option Price: \(result)")
    }
}

main()