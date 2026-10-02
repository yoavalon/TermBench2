struct SequenceGenerator {
    a: i32,
    b: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(a: i32, b: i32) -> Self {
        SequenceGenerator { a, b, current: a }
    }

    fn next(&mut self) -> i32 {
        self.current += self.b;
        self.current
    }
}

struct InventoryOptimizer {
    stock: i32,
    demand_sequence: SequenceGenerator,
    current_demand: i32,
}

impl InventoryOptimizer {
    fn new(initial_stock: i32, demand_sequence: SequenceGenerator) -> Self {
        InventoryOptimizer {
            stock: initial_stock,
            demand_sequence,
            current_demand: 0,
        }
    }

    fn update_stock(&mut self, supply: i32) {
        self.stock += supply;
    }

    fn process_demand(&mut self) {
        self.current_demand = self.demand_sequence.next();
        if self.stock >= self.current_demand {
            self.stock -= self.current_demand;
        } else {
            self.stock = 0;
        }
    }
}

struct SupplyChainSimulator {
    inventory_optimizer: InventoryOptimizer,
    supply_sequence: SequenceGenerator,
}

impl SupplyChainSimulator {
    fn new(
        initial_stock: i32,
        demand_a: i32,
        demand_b: i32,
        supply_a: i32,
        supply_b: i32,
    ) -> Self {
        SupplyChainSimulator {
            inventory_optimizer: InventoryOptimizer::new(
                initial_stock,
                SequenceGenerator::new(demand_a, demand_b),
            ),
            supply_sequence: SequenceGenerator::new(supply_a, supply_b),
        }
    }

    fn run(&mut self) {
        loop {
            let supply = self.supply_sequence.next();
            self.inventory_optimizer.update_stock(supply);
            self.inventory_optimizer.process_demand();
        }
    }
}

fn main() {
    let initial_stock = 100;
    let demand_a = 10;
    let demand_b = 5;
    let supply_a = 20;
    let supply_b = 10;
    let mut simulator = SupplyChainSimulator::new(initial_stock, demand_a, demand_b, supply_a, supply_b);
    simulator.run();
}