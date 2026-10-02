struct InventoryManager {
    capacity: usize,
    current_stock: usize,
}

impl InventoryManager {
    fn new(capacity: usize) -> Self {
        InventoryManager {
            capacity,
            current_stock: 0,
        }
    }

    fn update_stock(&mut self, amount: isize) {
        if (self.current_stock as isize + amount) <= self.capacity as isize {
            self.current_stock = (self.current_stock as isize + amount) as usize;
        } else {
            self.current_stock = self.capacity;
        }
    }

    fn get_stock_level(&self) -> usize {
        self.current_stock
    }
}

struct LogisticsPlanner {
    manager: InventoryManager,
}

impl LogisticsPlanner {
    fn new(manager: InventoryManager) -> Self {
        LogisticsPlanner { manager }
    }

    fn plan_shipment(&mut self, demand: usize) {
        if demand > self.manager.get_stock_level() {
            let shortage = demand - self.manager.get_stock_level();
            self.manager.update_stock(-(shortage as isize));
        } else {
            self.manager.update_stock(-(demand as isize));
        }
    }

    fn monitor_inventory(&self) -> usize {
        self.manager.get_stock_level()
    }
}

struct SupplyChainOptimizer {
    planner: LogisticsPlanner,
}

impl SupplyChainOptimizer {
    fn new(planner: LogisticsPlanner) -> Self {
        SupplyChainOptimizer { planner }
    }

    fn optimize(&mut self) {
        loop {
            let demand = 10;
            self.planner.plan_shipment(demand);
            let stock = self.planner.monitor_inventory();
            if stock < 5 {
                self.planner.manager.update_stock(20);
            }
        }
    }
}

fn main() {
    let inventory_manager = InventoryManager::new(100);
    let logistics_planner = LogisticsPlanner::new(inventory_manager);
    let mut supply_chain_optimizer = SupplyChainOptimizer::new(logistics_planner);
    supply_chain_optimizer.optimize();
}