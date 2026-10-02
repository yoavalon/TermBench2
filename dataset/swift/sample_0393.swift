import Foundation

func simulateOptions(prices: inout [Double], days: Int) -> AnyIterator<[Double]> {
    return AnyIterator {
        while true {
            for _ in 0..<days {
                for i in 0..<prices.count {
                    prices[i] *= 1 + (Double.random(in: 0...1) - 0.5) * 0.1
                }
            }
            return prices
        }
    }
}

func main() {
    var startPrices = [100.0, 150.0, 200.0]
    let days = 5
    let optionsGenerator = simulateOptions(prices: &startPrices, days: days)
    
    while let result = optionsGenerator.next() {
        print(result)
    }
}

main()