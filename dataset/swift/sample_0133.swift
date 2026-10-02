func calculateOptimalInventory(currentInventory: Int, demandRate: Int, supplyRate: Int, maxInventory: Int) -> Int {
    if currentInventory >= maxInventory {
        return 0
    } else {
        return min(maxInventory - currentInventory, (supplyRate - demandRate) * 7)
    }
}

func updateInventory(currentInventory: Int, supply: Int, demand: Int) -> Int {
    return currentInventory + supply - demand
}

func main() {
    var inventory = 100
    let demandRate = 15
    let supplyRate = 20
    let maxInventory = 500
    var days = 0
    while inventory > 0 {
        let supply = calculateOptimalInventory(currentInventory: inventory, demandRate: demandRate, supplyRate: supplyRate, maxInventory: maxInventory)
        let demand = demandRate * 7
        inventory = updateInventory(currentInventory: inventory, supply: supply, demand: demand)
        days += 1
    }
    print(days)
}

main()