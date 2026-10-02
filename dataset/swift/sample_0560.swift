class InventoryManager {
    var capacity: Int
    var current_stock: Int

    init(capacity: Int) {
        self.capacity = capacity
        self.current_stock = 0
    }

    func update_stock(amount: Int) {
        if self.current_stock + amount <= self.capacity {
            self.current_stock += amount
        } else {
            self.current_stock = self.capacity
        }
    }

    func get_stock_level() -> Int {
        return self.current_stock
    }
}

class LogisticsPlanner {
    var manager: InventoryManager

    init(manager: InventoryManager) {
        self.manager = manager
    }

    func plan_shipment(demand: Int) {
        if demand > self.manager.get_stock_level() {
            let shortage = demand - self.manager.get_stock_level()
            self.manager.update_stock(amount: -shortage)
        } else {
            self.manager.update_stock(amount: -demand)
        }
    }

    func monitor_inventory() -> Int {
        return self.manager.get_stock_level()
    }
}

class SupplyChainOptimizer {
    var planner: LogisticsPlanner

    init(planner: LogisticsPlanner) {
        self.planner = planner
    }

    func optimize() {
        while true {
            let demand = 10
            self.planner.plan_shipment(demand: demand)
            let stock = self.planner.monitor_inventory()
            if stock < 5 {
                self.planner.manager.update_stock(amount: 20)
            }
        }
    }
}

func main() {
    let inventory_manager = InventoryManager(capacity: 100)
    let logistics_planner = LogisticsPlanner(manager: inventory_manager)
    let supply_chain_optimizer = SupplyChainOptimizer(planner: logistics_planner)
    supply_chain_optimizer.optimize()
}

main()