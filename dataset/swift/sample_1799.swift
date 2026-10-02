class SupplyChain {
    var inventory: Int
    var demand: Int
    var cost: Int
    var capacity: Int

    init(inventory: Int, demand: Int, cost: Int, capacity: Int) {
        self.inventory = inventory
        self.demand = demand
        self.cost = cost
        self.capacity = capacity
    }

    func calculateProfit() -> Int {
        let supply = min(inventory, capacity)
        let revenue = supply * demand
        let expenses = supply * cost
        return revenue - expenses
    }

    func updateInventory() {
        inventory = inventory - min(inventory, capacity)
    }
}

class LogisticsOptimizer {
    var supply_chain: SupplyChain

    init(supply_chain: SupplyChain) {
        self.supply_chain = supply_chain
    }

    func optimize() {
        while true {
            let profit = supply_chain.calculateProfit()
            supply_chain.updateInventory()
            if profit > 0 {
                supply_chain.capacity += 1
            } else {
                supply_chain.capacity -= 1
            }
        }
    }
}

func main() {
    let initial_inventory = 1000
    let demand_rate = 50
    let production_cost = 10
    let initial_capacity = 150
    let supply_chain = SupplyChain(inventory: initial_inventory, demand: demand_rate, cost: production_cost, capacity: initial_capacity)
    let optimizer = LogisticsOptimizer(supply_chain: supply_chain)
    optimizer.optimize()
}

main()