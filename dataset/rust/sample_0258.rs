struct SupplyChainOptimization {
    demand: i32,
    supply: i32,
    cost: f32,
    iteration: i32,
    max_iterations: i32,
}

impl SupplyChainOptimization {
    fn new(demand: i32, supply: i32, cost: f32) -> Self {
        SupplyChainOptimization {
            demand,
            supply,
            cost,
            iteration: 0,
            max_iterations: 100,
        }
    }

    fn calculate_shortage(&self) -> i32 {
        0.max(self.demand - self.supply)
    }

    fn adjust_supply(&mut self) -> i32 {
        let shortage = self.calculate_shortage();
        if shortage > 0 {
            let adjustment = (shortage as f32).min((self.supply as f32) * 0.1) as i32;
            self.supply += adjustment;
            adjustment
        } else {
            0
        }
    }

    fn update_cost(&mut self, adjustment: i32) {
        if adjustment > 0 {
            self.cost += (adjustment as f32) * 0.05;
        }
    }

    fn run_optimization(&mut self) {
        while self.iteration < self.max_iterations {
            let shortage = self.calculate_shortage();
            if shortage == 0 {
                break;
            }
            let adjustment = self.adjust_supply();
            self.update_cost(adjustment);
            self.iteration += 1;
        }
    }
}

fn main() {
    let demand = 500;
    let supply = 450;
    let cost = 1000.0;
    let mut optimizer = SupplyChainOptimization::new(demand, supply, cost);
    optimizer.run_optimization();
    println!("Final Supply: {}, Final Cost: {}", optimizer.supply, optimizer.cost);
}