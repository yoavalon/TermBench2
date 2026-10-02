class SupplyChainOptimization {
    var demand_sequence: [Int]
    var production_capacity: Int
    var inventory: Int
    var backlog: Int
    var total_cost: Int
    var production_plan: [Int]

    init(demand_sequence: [Int], production_capacity: Int) {
        self.demand_sequence = demand_sequence
        self.production_capacity = production_capacity
        self.inventory = 0
        self.backlog = 0
        self.total_cost = 0
        self.production_plan = []
    }

    func calculateProduction(demand: Int) -> Int {
        if demand > production_capacity {
            let production = production_capacity
            backlog += demand - production_capacity
            return production
        } else {
            return demand
        }
    }

    func updateInventory(production: Int, demand: Int) {
        inventory += production - demand
    }

    func updateCost(production: Int, demand: Int) {
        if backlog > 0 {
            total_cost += backlog * 10
        }
        total_cost += production * 5
    }

    func runOptimization() {
        for demand in demand_sequence {
            let production = calculateProduction(demand: demand)
            production_plan.append(production)
            updateInventory(production: production, demand: demand)
            updateCost(production: production, demand: demand)
        }
    }
}

func main() {
    let demand_sequence = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550]
    let production_capacity = 250
    let optimizer = SupplyChainOptimization(demand_sequence: demand_sequence, production_capacity: production_capacity)
    optimizer.runOptimization()
    print("Total Cost:", optimizer.total_cost)
    print("Final Inventory:", optimizer.inventory)
    print("Final Backlog:", optimizer.backlog)
    print("Production Plan:", optimizer.production_plan)
}

main()