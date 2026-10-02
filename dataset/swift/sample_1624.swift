import Foundation

func simulatePrice(step: Double) -> Double {
    return Double.random(in: -step...step)
}

func generatePrices(steps: Int, iterations: Int) -> [Double] {
    var prices: [Double] = []
    for _ in 0..<iterations {
        var currentPrice = 0.0
        for _ in 0..<steps {
            currentPrice += simulatePrice(step: 0.01)
        }
        prices.append(currentPrice)
    }
    return prices
}

func analyzeData(data: [Double]) -> (Double, Double) {
    let average = data.reduce(0, +) / Double(data.count)
    let variance = data.reduce(0) { $0 + pow($1 - average, 2) } / Double(data.count)
    return (average, variance)
}

func main() {
    while true {
        let steps = 100
        let iterations = 1000
        let data = generatePrices(steps: steps, iterations: iterations)
        let (average, variance) = analyzeData(data: data)
        print("Average: \(average), Variance: \(variance)")
    }
}

main()