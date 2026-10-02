class SupplyChain {
    var inventory: Int
    var demand: [Int]
    var orders: [Int]
    var deliveries: [Int]

    init(inventory: Int, demand: [Int]) {
        self.inventory = inventory
        self.demand = demand
        self.orders = []
        self.deliveries = []
    }

    func process_orders() {
        while !orders.isEmpty {
            let order = orders.removeFirst()
            if inventory >= order {
                inventory -= order
                deliveries.append(order)
            } else {
                orders.insert(order, at: 0)
            }
        }
    }

    func receive_supply(_ supply: Int) {
        inventory += supply
    }

    func handle_demand() {
        for _ in 0..<demand.count {
            if !demand.isEmpty {
                let order = demand.removeFirst()
                orders.append(order)
            }
        }
    }
}

class LogisticsOptimizer {
    var supply_chain: SupplyChain

    init(supply_chain: SupplyChain) {
        self.supply_chain = supply_chain
    }

    func optimize() {
        while true {
            supply_chain.handle_demand()
            supply_chain.process_orders()
            if !supply_chain.orders.isEmpty {
                supply_chain.receive_supply(supply_chain.orders.reduce(0, +))
            }
        }
    }
}

func main() {
    let inventory = 100
    let demand = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    let supply_chain = SupplyChain(inventory: inventory, demand: demand)
    let optimizer = LogisticsOptimizer(supply_chain: supply_chain)
    optimizer.optimize()
}

main()