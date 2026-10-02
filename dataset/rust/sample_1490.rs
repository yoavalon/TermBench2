struct SupplyChain {
    inventory: i32,
    demand: i32,
    cost: i32,
}

impl SupplyChain {
    fn new(inventory: i32, demand: i32, cost: i32) -> SupplyChain {
        SupplyChain { inventory, demand, cost }
    }

    fn update_inventory(&mut self, supply: i32) {
        self.inventory += supply;
    }

    fn meet_demand(&mut self) -> (i32, i32) {
        if self.demand > self.inventory {
            let shortage = self.demand - self.inventory;
            (shortage, 0)
        } else {
            self.inventory -= self.demand;
            (0, self.demand)
        }
    }

    fn calculate_cost(&self) -> i32 {
        self.demand * self.cost
    }
}

struct Optimizer {
    supply_chain: SupplyChain,
    supply: i32,
}

impl Optimizer {
    fn new(supply_chain: SupplyChain, supply: i32) -> Optimizer {
        Optimizer { supply_chain, supply }
    }

    fn optimize(&mut self) -> (i32, i32, i32) {
        self.supply_chain.update_inventory(self.supply);
        let (shortage, fulfilled) = self.supply_chain.meet_demand();
        let cost = self.supply_chain.calculate_cost();
        (shortage, fulfilled, cost)
    }
}

fn main() {
    let inventory = 100;
    let demand = 150;
    let cost = 10;
    let supply = 60;
    let mut supply_chain = SupplyChain::new(inventory, demand, cost);
    let mut optimizer = Optimizer::new(supply_chain, supply);
    let (shortage, fulfilled, cost) = optimizer.optimize();
    println!("Shortage: {}, Fulfilled: {}, Cost: {}", shortage, fulfilled, cost);
}