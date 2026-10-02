struct SupplyChain {
    inventory: i32,
    demand: Vec<i32>,
    orders: Vec<i32>,
    deliveries: Vec<i32>,
}

impl SupplyChain {
    fn new(inventory: i32, demand: Vec<i32>) -> Self {
        SupplyChain {
            inventory,
            demand,
            orders: Vec::new(),
            deliveries: Vec::new(),
        }
    }

    fn process_orders(&mut self) {
        while !self.orders.is_empty() {
            let order = self.orders.remove(0);
            if self.inventory >= order {
                self.inventory -= order;
                self.deliveries.push(order);
            } else {
                self.orders.insert(0, order);
            }
        }
    }

    fn receive_supply(&mut self, supply: i32) {
        self.inventory += supply;
    }

    fn handle_demand(&mut self) {
        for _ in 0..self.demand.len() {
            if !self.demand.is_empty() {
                let order = self.demand.remove(0);
                self.orders.push(order);
            }
        }
    }
}

struct LogisticsOptimizer {
    supply_chain: SupplyChain,
}

impl LogisticsOptimizer {
    fn new(supply_chain: SupplyChain) -> Self {
        LogisticsOptimizer { supply_chain }
    }

    fn optimize(&mut self) {
        loop {
            self.supply_chain.handle_demand();
            self.supply_chain.process_orders();
            if !self.supply_chain.orders.is_empty() {
                let total_orders: i32 = self.supply_chain.orders.iter().sum();
                self.supply_chain.receive_supply(total_orders);
            }
        }
    }
}

fn main() {
    let inventory = 100;
    let demand = vec![10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let supply_chain = SupplyChain::new(inventory, demand);
    let mut optimizer = LogisticsOptimizer::new(supply_chain);
    optimizer.optimize();
}