struct SupplyChain {
    demand: i32,
    supply: i32,
    inventory: i32,
    shortage: i32,
}

impl SupplyChain {
    fn new(demand: i32, supply: i32) -> SupplyChain {
        SupplyChain {
            demand,
            supply,
            inventory: supply,
            shortage: 0,
        }
    }

    fn update_inventory(&mut self) {
        if self.demand > self.supply {
            self.shortage = self.demand - self.supply;
            self.inventory = 0;
        } else {
            self.inventory -= self.demand;
            self.shortage = 0;
        }
    }

    fn adjust_supply(&mut self, adjustment: i32) {
        self.supply += adjustment;
    }
}

struct Optimizer {
    supply_chain: SupplyChain,
}

impl Optimizer {
    fn new(supply_chain: SupplyChain) -> Optimizer {
        Optimizer { supply_chain }
    }

    fn optimize(&mut self) {
        let shortage = self.supply_chain.shortage;
        if shortage > 0 {
            let adjustment = shortage * 110 / 100;
            self.supply_chain.adjust_supply(adjustment);
        }
    }
}

fn main() {
    let demand = 150;
    let supply = 100;
    let mut supply_chain = SupplyChain::new(demand, supply);
    let mut optimizer = Optimizer::new(supply_chain);
    loop {
        supply_chain.update_inventory();
        optimizer.optimize();
    }
}