struct SequenceGenerator {
    current: i32,
    increment: i32,
}

impl SequenceGenerator {
    fn new(start: i32, increment: i32) -> Self {
        SequenceGenerator { current: start, increment }
    }

    fn generate(&mut self, count: usize) -> Vec<i32> {
        let mut sequence = Vec::new();
        for _ in 0..count {
            sequence.push(self.current);
            self.current += self.increment;
        }
        sequence
    }
}

struct SupplyChainOptimizer {
    demand: i32,
    supply: i32,
}

impl SupplyChainOptimizer {
    fn new(demand: i32, supply: i32) -> Self {
        SupplyChainOptimizer { demand, supply }
    }

    fn calculate_deficit(&self) -> i32 {
        let deficit = self.demand - self.supply;
        if deficit > 0 {
            deficit
        } else {
            0
        }
    }

    fn optimize_supply(&mut self, additional_supply: i32) {
        self.supply += additional_supply;
    }
}

struct SupplyChain {
    demand_sequence: Vec<i32>,
    supply_sequence: Vec<i32>,
    optimizer: SupplyChainOptimizer,
}

impl SupplyChain {
    fn new(demand_sequence: Vec<i32>, supply_sequence: Vec<i32>) -> Self {
        SupplyChain {
            demand_sequence,
            supply_sequence,
            optimizer: SupplyChainOptimizer::new(0, 0),
        }
    }

    fn run_optimization(&mut self) {
        for (demand, supply) in self.demand_sequence.iter().zip(self.supply_sequence.iter()) {
            self.optimizer.supply = *supply;
            let deficit = self.optimizer.calculate_deficit();
            if deficit > 0 {
                let additional_supply = SequenceGenerator::new(deficit, 1).generate(1)[0];
                self.optimizer.optimize_supply(additional_supply);
            }
            println!("Demand: {}, Supply: {}, Deficit: {}, Adjusted Supply: {}", demand, supply, deficit, self.optimizer.supply);
        }
    }
}

fn main() {
    let mut demand_gen = SequenceGenerator::new(100, 10);
    let demand_sequence = demand_gen.generate(10);
    let mut supply_gen = SequenceGenerator::new(80, 5);
    let supply_sequence = supply_gen.generate(10);
    let mut supply_chain = SupplyChain::new(demand_sequence, supply_sequence);
    supply_chain.run_optimization();
}