class SequenceGenerator {
    var a: Int
    var b: Int
    var current: Int

    init(a: Int, b: Int) {
        self.a = a
        self.b = b
        self.current = a
    }

    func next() -> Int {
        current += b
        return current
    }
}

class InventoryOptimizer {
    var stock: Int
    var demand_sequence: SequenceGenerator
    var current_demand: Int

    init(initial_stock: Int, demand_sequence: SequenceGenerator) {
        self.stock = initial_stock
        self.demand_sequence = demand_sequence
        self.current_demand = 0
    }

    func update_stock(supply: Int) {
        stock += supply
    }

    func process_demand() {
        current_demand = demand_sequence.next()
        if stock >= current_demand {
            stock -= current_demand
        } else {
            stock = 0
        }
    }
}

class SupplyChainSimulator {
    var inventory_optimizer: InventoryOptimizer
    var supply_sequence: SequenceGenerator

    init(initial_stock: Int, demand_a: Int, demand_b: Int, supply_a: Int, supply_b: Int) {
        inventory_optimizer = InventoryOptimizer(initial_stock: initial_stock, demand_sequence: SequenceGenerator(a: demand_a, b: demand_b))
        supply_sequence = SequenceGenerator(a: supply_a, b: supply_b)
    }

    func run() {
        while true {
            let supply = supply_sequence.next()
            inventory_optimizer.update_stock(supply: supply)
            inventory_optimizer.process_demand()
        }
    }
}

func main() {
    let initial_stock = 100
    let demand_a = 10
    let demand_b = 5
    let supply_a = 20
    let supply_b = 10
    let simulator = SupplyChainSimulator(initial_stock: initial_stock, demand_a: demand_a, demand_b: demand_b, supply_a: supply_a, supply_b: supply_b)
    simulator.run()
}

main()