func optimizeSupplyChain(data: [[String: Double]]) -> Double {
    var totalCost = 0.0
    for item in data {
        totalCost += item["quantity"]! * item["price"]!
    }
    return round(totalCost * 100) / 100
}

func main() {
    let data = [["quantity": 150.75, "price": 2.34], ["quantity": 200.5, "price": 1.8], ["quantity": 120.25, "price": 3.15]]
    let result = optimizeSupplyChain(data: data)
    print(result)
}

main()