func calculateCost(units: Int, price: Int, discount: Double) -> Double {
    if units > 100 {
        return Double(units) * Double(price) * (1 - discount)
    }
    return Double(units) * Double(price)
}

func optimizeSupplyChain(demand: Int, supply: Int, costPerUnit: Int) -> Double {
    if demand > supply {
        let shortage = demand - supply
        let adjustedCost = calculateCost(units: shortage, price: costPerUnit, discount: 0.05)
        return adjustedCost
    }
    return 0
}

func main() {
    let demand = 120
    let supply = 100
    let costPerUnit = 10
    let additionalCost = optimizeSupplyChain(demand: demand, supply: supply, costPerUnit: costPerUnit)
    print("Additional cost due to shortage: \(additionalCost)")
}

main()