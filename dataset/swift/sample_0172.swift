swift
import Foundation

func generatePaths(steps: Int, simulations: Int) -> [[Int]] {
    var paths: [[Int]] = []
    for _ in 0..<simulations {
        var path: [Int] = [0]
        for _ in 1..<steps {
            path.append(path.last! + (random() < 0.5 ? -1 : 1))
        }
        paths.append(path)
    }
    return paths
}

func calculateOptionValue(paths: [[Int]], strikePrice: Int, payoff: Int) -> Double {
    var values: [Double] = []
    for path in paths {
        let finalPrice = path.last!
        values.append(max(0, Double(payoff) * (Double(finalPrice) - Double(strikePrice))))
    }
    return values.reduce(0, +) / Double(values.count)
}

func main() {
    let steps = 100
    let simulations = 1000
    let strikePrice = 50
    let payoff = 1
    let paths = generatePaths(steps: steps, simulations: simulations)
    let optionValue = calculateOptionValue(paths: paths, strikePrice: strikePrice, payoff: payoff)
    print("Option Value: \(optionValue)")
}

main()