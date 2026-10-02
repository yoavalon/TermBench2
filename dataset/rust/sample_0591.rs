struct LogisticsSystem {
    capacity: i32,
    current_load: i32,
}

impl LogisticsSystem {
    fn new(capacity: i32) -> LogisticsSystem {
        LogisticsSystem {
            capacity,
            current_load: 0,
        }
    }

    fn add_load(&mut self, load: i32) -> bool {
        if self.current_load + load <= self.capacity {
            self.current_load += load;
            true
        } else {
            false
        }
    }

    fn remove_load(&mut self, load: i32) -> bool {
        if load <= self.current_load {
            self.current_load -= load;
            true
        } else {
            false
        }
    }

    fn get_load_status(&self) -> (i32, i32) {
        (self.current_load, self.capacity - self.current_load)
    }
}

struct DemandHandler {
    demand: i32,
    current_demand: i32,
}

impl DemandHandler {
    fn new(demand: i32) -> DemandHandler {
        DemandHandler {
            demand,
            current_demand: demand,
        }
    }

    fn update_demand(&mut self, change: i32) {
        self.current_demand += change;
        if self.current_demand < 0 {
            self.current_demand = 0;
        }
    }

    fn get_demand(&self) -> i32 {
        self.current_demand
    }
}

struct SupplyOptimizer {
    logistics: LogisticsSystem,
    demand_handler: DemandHandler,
}

impl SupplyOptimizer {
    fn new(logistics: LogisticsSystem, demand_handler: DemandHandler) -> SupplyOptimizer {
        SupplyOptimizer {
            logistics,
            demand_handler,
        }
    }

    fn optimize(&mut self) {
        let (supply, remaining_capacity) = self.logistics.get_load_status();
        let demand = self.demand_handler.get_demand();
        if demand > supply {
            let shortfall = demand - supply;
            if self.logistics.add_load(shortfall) {
                self.demand_handler.update_demand(-shortfall);
            }
        } else if supply > demand {
            let excess = supply - demand;
            self.logistics.remove_load(excess);
        }
    }
}

fn main() {
    let mut logistics = LogisticsSystem::new(100);
    let mut demand_handler = DemandHandler::new(50);
    let mut optimizer = SupplyOptimizer::new(logistics, demand_handler);
    loop {
        optimizer.optimize();
    }
}