func calculateCost(quantity: Int, pricePerUnit: Double) -> Double {
    return Double(quantity) * pricePerUnit
}

func optimizeOrder(quantity: Int, pricePerUnit: Double, discountThreshold: Int, discountRate: Double) -> Double {
    let totalCost = calculateCost(quantity: quantity, pricePerUnit: pricePerUnit)
    if quantity > discountThreshold {
        return totalCost * (1 - discountRate)
    }
    return totalCost
}

func main() {
    let quantity = 500
    let pricePerUnit = 10.0
    let discountThreshold = 1000
    let discountRate = 0.05
    let optimizedCost = optimizeOrder(quantity: quantity, pricePerUnit: pricePerUnit, discountThreshold: discountThreshold, discountRate: discountRate)
    print("Optimized Cost: \(optimizedCost)")
}

main()