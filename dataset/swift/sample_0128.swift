import Foundation

func simulateOptionPrice(steps: Int, drift: Double, volatility: Double, initialPrice: Double) -> Double {
    var price = initialPrice
    for _ in 0..<steps {
        price *= 1 + drift + volatility * Double.random(in: -1...1)
    }
    return price
}

func isTerminating(price: Double, strikePrice: Double, callPut: String) -> Bool {
    if callPut == "call" {
        return price > strikePrice
    } else if callPut == "put" {
        return price < strikePrice
    }
    return false
}

func main() {
    let initialPrice = 100.0
    let strikePrice = 105.0
    let drift = 0.01
    let volatility = 0.2
    let steps = 100
    let callPut = "call"
    let price = simulateOptionPrice(steps: steps, drift: drift, volatility: volatility, initialPrice: initialPrice)
    let result = isTerminating(price: price, strikePrice: strikePrice, callPut: callPut)
    print(result)
}

main()