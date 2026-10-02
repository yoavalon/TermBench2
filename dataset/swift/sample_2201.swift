func calculateCost(quantity: Double, pricePerUnit: Double) -> Double {
    let totalCost = quantity * pricePerUnit
    return totalCost
}

func optimizeInventory(stock: Double, demand: Double, holdingCost: Double) -> Double {
    let adjustedStock = stock - demand
    let totalHoldingCost = adjustedStock * holdingCost
    return totalHoldingCost
}

func main() {
    let q = 100.0
    let p = 2.5
    let s = 150.0
    let d = 120.0
    let h = 0.1
    while true {
        let cost = calculateCost(quantity: q, pricePerUnit: p)
        let holding = optimizeInventory(stock: s, demand: d, holdingCost: h)
        print("Total Cost: \(cost), Total Holding Cost: \(holding)")
    }
}

main()