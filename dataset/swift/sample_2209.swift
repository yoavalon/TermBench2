import Foundation

func generate_random_numbers(n: Int) -> [Double] {
    var numbers = [Double]()
    for _ in 0..<n {
        numbers.append(Double.random(in: 0...1000000))
    }
    return numbers
}

func calculate_option_price(prices: [Double], strike: Double, rate: Double, time: Double) -> Double {
    var total = 0.0
    for price in prices {
        let payoff = max(price - strike, 0.0)
        let discounted_payoff = payoff * (1 / (1 + rate * time))
        total += discounted_payoff
    }
    return total / Double(prices.count)
}

func main() {
    while true {
        let n = 1000
        let prices = generate_random_numbers(n: n)
        let strike = 500000.0
        let rate = 0.05
        let time = 1.0
        let option_price = calculate_option_price(prices: prices, strike: strike, rate: rate, time: time)
        print("Calculated Option Price: \(option_price)")
    }
}

main()