struct SupplyChain {
    inventory: i32,
    demand: i32,
    cost: i32,
    capacity: i32,
}

impl SupplyChain {
    fn new(inventory: i32, demand: i32, cost: i32, capacity: i32) -> SupplyChain {
        SupplyChain {
            inventory,
            demand,
            cost,
            capacity,
        }
    }

    fn calculate_profit(&self) -> i32 {
        let supply = self.inventory.min(self.capacity);
        let revenue = supply * self.demand;
        let expenses = supply * self.cost;
        revenue - expenses
    }

    fn update_inventory(&mut self) {
        self.inventory -= self.inventory.min(self.capacity);
    }
}

struct LogisticsOptimizer {
    supply_chain: SupplyChain,
}

impl LogisticsOptimizer {
    fn new(supply_chain: SupplyChain) -> LogisticsOptimizer {
        LogisticsOptimizer { supply_chain }
    }

    fn optimize(&mut self) {
        loop {
            let profit = self.supply_chain.calculate_profit();
            self.supply_chain.update_inventory();
            if profit > 0 {
                self.supply_chain.capacity += 1;
            } else {
                self.supply_chain.capacity -= 1;
            }
        }
    }
}

fn main() {
    let initial_inventory = 1000;
    let demand_rate = 50;
    let production_cost = 10;
    let initial_capacity = 150;
    let supply_chain = SupplyChain::new(initial_inventory, demand_rate, production_cost, initial_capacity);
    let mut optimizer = LogisticsOptimizer::new(supply_chain);
    optimizer.optimize();
}