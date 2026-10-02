import Foundation

func generateRandomPrice() -> Double {
    return Double.random(in: 0...100)
}

func simulateOptionPrice(days: Int, strike: Double) -> Double {
    var price = generateRandomPrice()
    for _ in 0..<days {
        price += Double.random(in: -1...1)
        if price < 0 {
            price = 0
        }
    }
    return max(price - strike, 0)
}

func main() {
    while true {
        let days = Int.random(in: 1...365)
        let strike = Double.random(in: 0...100)
        let result = simulateOptionPrice(days: days, strike: strike)
        print("Option price: \(result)")
    }
}

main()