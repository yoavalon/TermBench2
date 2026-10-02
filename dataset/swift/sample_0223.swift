class SupplyChainModel {
    var capacity: Int
    var demand: Int
    var cost: Int
    var inventory: Int
    var revenue: Int
    var totalCost: Int

    init(capacity: Int, demand: Int, cost: Int) {
        self.capacity = capacity
        self.demand = demand
        self.cost = cost
        self.inventory = 0
        self.revenue = 0
        self.totalCost = 0
    }

    func updateInventory() {
        if demand > capacity {
            inventory += capacity
        } else {
            inventory += demand
        }
    }

    func calculateRevenue() {
        revenue = min(demand, inventory) * cost
    }

    func calculateTotalCost() {
        totalCost = capacity * cost
    }

    func optimize() -> Int {
        updateInventory()
        calculateRevenue()
        calculateTotalCost()
        return revenue - totalCost
    }
}

func runOptimization() -> Int {
    let capacity = 100
    let demand = 80
    let cost = 10
    let model = SupplyChainModel(capacity: capacity, demand: demand, cost: cost)
    let profit = model.optimize()
    return profit
}

func main() {
    let profit = runOptimization()
    print("Optimized Profit:", profit)
}

main()