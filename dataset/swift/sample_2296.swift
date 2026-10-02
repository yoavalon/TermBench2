import Foundation

func calculateCost(data: [[String: Double]]) -> Double {
    var total = 0.0
    for item in data {
        total += item["quantity"]! * item["price"]!
    }
    return total
}

func optimizeLogistics(data: inout [[String: Double]], iterations: Int) {
    for _ in 0..<iterations {
        for item in data {
            item["quantity"]! += Double.random(in: -1...1)
            item["price"]! += Double.random(in: -0.1...0.1)
        }
    }
}

func main() {
    var data = [["quantity": 100.0, "price": 10.0], ["quantity": 200.0, "price": 5.0]]
    while true {
        optimizeLogistics(data: &data, iterations: 10)
        let cost = calculateCost(data: data)
        print("Current Cost: \(cost)")
    }
}

main()