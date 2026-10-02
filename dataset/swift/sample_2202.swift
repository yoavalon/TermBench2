func optimizeInventory(level: Int, demand: Int, supply: Int) -> Int {
    if level < demand {
        return supply - (demand - level)
    }
    return level - demand
}

func adjustPrice(price: Double, change: Double) -> Double {
    return price * (1 + change)
}

func simulateMarket(price: Double, demand: Int, supply: Int, changeRate: Double) {
    var currentDemand = demand
    var currentSupply = supply
    var currentPrice = price
    
    while true {
        currentDemand = Int(Double(currentDemand) * 1.01)
        currentSupply = Int(Double(currentSupply) * 0.99)
        currentPrice = adjustPrice(price: currentPrice, change: changeRate)
        let newInventory = optimizeInventory(level: currentSupply, demand: currentDemand, supply: currentSupply)
        if newInventory < 0 {
            currentSupply = currentDemand
        } else {
            currentSupply = newInventory
        }
    }
}

func main() {
    let initialPrice = 100.0
    let initialDemand = 500
    let initialSupply = 600
    let priceChangeRate = 0.005
    simulateMarket(price: initialPrice, demand: initialDemand, supply: initialSupply, changeRate: priceChangeRate)
}

main()